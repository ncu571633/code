#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
 
template <typename T>
class BlockingBoundedQueue
{
    public:
        BlockingBoundedQueue() {
            q = nullptr;
            capacity = 0;
        }

        void init(int n) {
            mutex_.lock();
            try {
                if(q) {
                    throw;
                } else {
                    q = new(queue<int>);
                    capacity = n;
                }
            } catch(...) {
                
            }
            mlock.unlock();
        }

        void pop(T& item)
        {
            mutex_.lock();
            
            while (q.empty())
            {
                notEmpty.wait(mlock);
            }
            item = q.front();
            q.pop();
            notFull.notifyAll();
            
            mlock.unlock();
        }

        void push(T&& item)
        {
            mutex_.lock();
            
            while (q.size() == capacity)
            {
                notFull.wait(mlock);
            }
            q.push(std::move(item));
            notEmpty.notify_all();
            
            mlock.unlock();
        }

    private:
        std::queue<T> q;
        int capacity;
        std::mutex mutex_;
        std::condition_variable notEmpty;
        std::condition_variable notFull;
};


 public void init(int capacity) throws Exception {
     this.lock.lock();
     try{
         if(this.queue == null){
             this.queue = new LinkedList<>();
             this.capacity = capacity;
         } else {
             throw new Exception();
         }
     }finally{
         this.lock.unlock();
     }
 }

 // throws Exception if the queue is not initialized
 public void push(E obj) throws Exception {
     this.pushLock.lock();
      this.lock.lock();
     try{
         while(this.capacity == this.queue.size())
             this.notFull.wait();
         this.queue.add(obj);
         this.notEmpty.notifyAll();
     }finally{
         this.lock.unlock();
         this.pushLock.lock();
     }
 }

 // throws Exception if the queue is not initialized
 public E pop() throws Exception {
     this.lock.lock();
     try{
         while(this.capacity==0)
             this.notEmpty.wait();
         E result = this.queue.poll();
         notFull.notifyAll();
         return result;
     }finally{
         this.lock.unlock();
     }
 }
