class BoundedBlockingQueue 
{
    queue<int> q; // The queue that holds the elements
    mutex mtx; // Mutex to protect access to the queue
    condition_variable cv1; // Condition variable to block enqueue when queue is full
    condition_variable cv2; // Condition variable to block dequeue when queue is empty
    int capacity; // Maximum number of items in the queue
    int count; // Current number of items in the queue

public:
    BoundedBlockingQueue(int Capacity) :capacity(Capacity), count(0)
    {
        
    }
    
    void enqueue(int element) 
    {
        {
            unique_lock<mutex>lock(mtx);
            // Wait until there is space in the queue
            cv1.wait(lock, [this] { return count < capacity;});
            q.push(element);
            ++count;
        }
        // Notify one waiting thread (if any) that an item was dequeued
        cv2.notify_one();
    }

    int dequeue() 
    {
        unique_lock<mutex>lock(mtx);
        cv2.wait(lock, [this] {return count>0;});
        int value=q.front();
        q.pop();
        count--;
        cv1.notify_one();
        return value;
    }
    
    int size() 
    {
        unique_lock<mutex>lock(mtx);
        return count;
    }
};