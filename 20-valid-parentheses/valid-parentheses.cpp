class Solution {
public:
    bool isValid(string str)
    {
        // Declare a stack to hold the previous brackets.
        stack<char> temp;
        for (int i = 0; i < str.length(); i++)
        {
            if (temp.empty()) 
            {
                // Initially the stack will be empty
                // Also the stack will be emty aftr the pop
                // If the stack is empty push the current bracket
                temp.push(str[i]);
            }
            else if ((temp.top() == '(' && str[i] == ')')
                 || (temp.top() == '{' && str[i] == '}')
                 || (temp.top() == '[' && str[i] == ']')) 
            {
                // If we found any complete pair of bracket
                // then pop
                temp.pop();
            }
            else 
            {
                // keep pushing until the match
                temp.push(str[i]);
            }
        }
    if (temp.empty())
    {
        
        // If stack is empty return true
        return true;
    }
    return false;
}
};