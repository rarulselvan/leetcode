class Solution 
{
public:
    int maxRepeating(string sequence, string word) 
    {
        int res = 0;
        string repeating = word;
        while (sequence.find(repeating) != string::npos) 
        {
            res++;
            repeating = repeating + word;
        }
        return res ;
    }
};