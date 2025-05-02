class Codec 
{
public:
    
    string encode(vector<string>& strs) 
    {
        string ans;
        for (string s : strs) 
        {
            int size = s.size();
            ans += string((const char*) &size, sizeof(size));
            ans += s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) 
    {
        vector<string> ans;
        int right = 0;
        int len = s.size();
        int size = 0;
        while (right < len) 
        {
            memcpy(&size, s.data() + right, 4);
            right = right + sizeof(size);//move the length in the length procedded string
            ans.push_back(s.substr(right, size));
            right = right+size;//move until the string ends
        }
        return ans;
    }
};