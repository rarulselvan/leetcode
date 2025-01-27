class BrowserHistory 
{
private:
    stack<string> stk1;
    stack<string> stk2;
public:

    BrowserHistory(string homepage) 
    {
        visit(homepage);
    }

    void visit(string url)
    {
        stk1.push(url);
        //Clear the stack (strk2) ..instead of pop() all the elements this will clear the stack at one go
        stk2 = stack<string>();
    }

    string back(int steps) 
    {
        for (int i=0; i<steps && 1<stk1.size(); steps--) 
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        return stk1.top();
    }

    string forward(int steps) 
    {
        for (int i=0; i<steps && !stk2.empty(); steps--) 
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return stk1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */