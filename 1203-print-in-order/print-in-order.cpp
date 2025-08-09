class Foo 
{
    mutex mtx;
    condition_variable cv;
    int count=1;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) 
    {
        unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[this]{return count==1;});
        printFirst();
        count=2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) 
    {
        unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[this]{return count==2;});
        printSecond();
        count=3;
        cv.notify_all();
    }

    void third(function<void()> printThird) 
    {
        
          unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]{return count==3;});
        printThird();
        count=2;
        cv.notify_all();
    }
};