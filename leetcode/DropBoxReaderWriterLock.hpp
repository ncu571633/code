

https://www.cs.cmu.edu/~fp/courses/15213-s05/recitations/secF_4-25.pdf

Concurrency Example – Readers/Writers Locks

Implementation 1 - Mutex
/* Add a mutex and a count to Blackbox: */ 
typedef struct blackbox { 
  // Some stuff that we don't know about 
  volatile int reader_count; 
  pthread_mutex_t lock; 
} Blackbox; 
char *ts_read(Blackbox *b) 
{ 
  char *buf; 
  pthread_mutex_lock(&b->lock); 
  b->reader_count++; 
  pthread_mutex_unlock(&b->lock); 
  buf = read(b); 
  pthread_mutex_lock(&b->lock); 
  b->reader_count--; 
  pthread_mutex_unlock(&b->lock); 
} 
void ts_write(BlackBox *b, const char *buf) { 
  int written = FALSE; 
  while (!written) 
  { 
    pthread_mutex_lock(&b->lock); 
    if (b->reader_count == 0) 
    { 
      write(b, buf); 
      written = TRUE; 
    } 
    pthread_mutex_unlock(&b->lock); 
  } 
}

/* This implementation ensures that if there are an
y writes 
 * pending, they will occur before any reads are pe
rmitted, 
 * minimizing the risk of starvation in the common 
case 
 * (many readers, few writers). 
 */ 
/* Add a mutex and a count to Blackbox: */ 
typedef struct blackbox { 
  // Some stuff that we don't know about 
  volatile int num_reads_in_prog; 
  volatile int num_writes; // waiting or in progres
s 
  pthread_cond_t reader_cv; 
  pthread_cond_t writer_cv; 
  pthread_mutex_t lock; 
} Blackbox; 
/* Pre-condition: b->lock must be locked before thi
s function 
 * is called 
 */ 
void signal_next(BlackBox *b) 
{ 
  if (b->num_writes > 0) 
  { 
    // If any writes are waiting, wake one up 
    pthread_cond_signal(&b->writer_cv); 
  } 
  else 
  { 
    // If there are no writes pending, wake up all the 
    // readers (there may not be any but that's fine) 
    pthread_cond_broadcast(&b->reader_cv); 
  } 
} 
char *ts_read(Blackbox *b) 
{ 
  char *buf; 
  pthread_mutex_lock(&b->lock); 
  while (b->num_writes > 0) 
  { 
    // cond_wait unlocks the mutex, waits to be sig
naled,  
    // then re-acquires the mutex 
    pthread_cond_wait(&b->reader_cv, &b->lock); 
  } 
  // By here b->num_writes must be 0 
  b->num_reads_in_prog++; 
  pthread_mutex_unlock(&b->lock); 
  buf = read(b); 
  pthread_mutex_lock(&b->lock); 
  b->num_reads_in_prog--; 
  signal_next(b); 
  pthread_mutex_unlock(&b->lock); 
} 
void ts_write(BlackBox *b, const char *buf) { 
  pthread_mutex_lock(&b->lock); 
  b->num_writes++; 
  // Don't need a while here because we will always
 be able to 
  // run if we are signaled 
  if (b->num_writes > 1 || b->num_reads_in_prog > 0
) 
  { 
    // cond_wait unlocks the mutex, waits to be sig
naled,  
    // then re-acquires the mutex 
    pthread_cond_wait(&b->writer_cv, &b->lock); 
  } 
  pthread_mutex_unlock(&b->lock); 
  write(b, buf); 
  pthread_mutex_lock(&b->lock); 
  b->num_writes--; 
  signal_next(b); 
  pthread_mutex_unlock(&b->lock); 
} 

