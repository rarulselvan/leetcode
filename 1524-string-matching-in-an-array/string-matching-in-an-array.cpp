class Solution 
{
public:
    // Function to find all strings in 'words' that are substrings of other strings
    vector<string> stringMatching(vector<string>& words)
    {
        vector<string> res;
        int numWords = words.size(); // Number of words in the input vector

        for(string s1 : words)
        {
            cout <<endl;
            for (string s2:words) 
            {
                cout <<s1<<" " <<s2<<endl;
                if (s1 == s2)
                    continue;

                if(s2.find(s1) != string::npos) 
                {
                    res.push_back(s1); 
                    break;
                }
            }
        }
        return res;
    }
};