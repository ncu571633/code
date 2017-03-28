#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
 
template <typename T>
class Queue
{
 public:
 
  void pop(T& item)
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    while (queue_.empty())
    {
      cond_.wait(mlock);
    }
    item = queue_.front();
    queue_.pop();
  }
 
  void push(T&& item)
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    queue_.push(std::move(item));
    mlock.unlock();
    cond_.notify_one();
  }
 
 private:
  std::queue<T> queue_;
  std::mutex mutex_;
  std::condition_variable cond_;
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

