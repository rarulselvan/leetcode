class MyQueue 
{
    stack<int> s1, s2;

public:
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        //migrate s1 into s2
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        //bring back s2 into s1
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() 
    {
        int x=s1.top();
        s1.pop();
        return x;    
    }
    
    int peek() 
    {
        int x=s1.top();
        return x;    
    }
    
    bool empty() 
    {
        if(s1.size()==0)
            return true;
        else
            return false;    
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */