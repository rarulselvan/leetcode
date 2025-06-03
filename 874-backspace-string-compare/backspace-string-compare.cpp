class Solution 
{
public:
    bool backspaceCompare(string s, string t) 
    {
        if(removeBackspaces(s)==removeBackspaces(t))
            return true;
        else
            return false;
    }
    string removeBackspaces(string &s)
    {
        int n = s.size();

        // To point at position after considering the
        // backspaces
        int idx = 0;

        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] != '#') 
            {
                s[idx] = s[i];
                idx++;
            }
            else if (s[i] == '#' && idx >= 0) 
                idx--;

            // This idx can never point at negative index
            // position
           
         if (idx < 0)
               idx = 0;
        }
        cout <<s<<endl;
         if (idx < 0)
            idx = 0;
        return s.substr(0, idx);
    }
};