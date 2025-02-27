class Solution 
{
public:
    int calculate(string s) 
    {
        int num = 0;
        int n = s.size();
        char preSign = '+';// First number ..push into empty stack..that is bottom
        stack<int> myStack;

        for (int i = 0; i < n; ++i) 
        {
            char c = s[i];
            if (isdigit(c)) 
            {
                num = num * 10 + (c - '0');//char start from 48-59 (i.e '0' ... '9') ..so if you substract '0' ..the CII values will start from 0...9 got the  idea?
                //gather the number i,e if the stream has "123+2"...First 123 is extracted here and stored in "num" varibale
            }
            //Get into this block for " +, -, *, / " and if the last char...complete the operation
            if (i == n - 1 || c == '+' || c == '-' || c == '*' || c == '/') 
            {
                if (preSign == '+')
                    myStack.push(num);
                else if (preSign == '-')
                    myStack.push(-num);
                else if (preSign == '*') 
                {
                    int t = myStack.top();
                    myStack.pop();
                    myStack.push(t * num);
                } 
                else
                {
                    int t = myStack.top();
                    myStack.pop();
                    myStack.push(t / num);
                }
                preSign = c;
                num = 0;
            }
        }
        int ans = 0;
        while (!myStack.empty()) 
        {
            ans += myStack.top();
            myStack.pop();
        }
        return ans;
    }
};
