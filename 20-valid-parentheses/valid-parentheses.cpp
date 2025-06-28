class Solution 
{
public:
    bool isValid(string s) 
    {
        stack <char> st;

        for(char x: s)
        {
            if(st.empty())
                st.push(x);
            else
            {
                char temp=st.top();
                if(temp=='(' && x==')')
                    st.pop();
                else if(temp=='{' && x=='}')
                    st.pop();
                else if(temp=='[' && x==']')
                    st.pop();
                else
                    st.push(x);
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};