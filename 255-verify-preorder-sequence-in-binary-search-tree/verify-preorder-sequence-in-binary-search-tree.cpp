
class Solution 
{
public:
    bool verifyPreorder(vector<int>& preorder) 
    {
        stack<int> s;
        int last = numeric_limits<int>::min();

        for (int value : preorder) 
        {
            if (value < last)
                return false;

            while (!s.empty() && value > s.top()) 
            {
                last = s.top();
                s.pop();
            }
            s.push(value);
        }
        return true;
    }
};