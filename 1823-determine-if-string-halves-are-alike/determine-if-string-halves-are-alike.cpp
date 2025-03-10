class Solution 
{
public:
    bool halvesAreAlike(string s) 
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt1 = 0;
        int cnt2=0;
        int  n = s.size() / 2;
        for (int i = 0; i < n; ++i) 
        {
            cnt1 += vowels.count(s[i]);
            cnt2 += vowels.count(s[i + n]);
        }
        return cnt1 == cnt2 ? true:false;
    }
};