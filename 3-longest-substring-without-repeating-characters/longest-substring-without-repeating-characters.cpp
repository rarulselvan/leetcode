class Solution 
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> myMap;
        int res = 0;
        int j = 0;
        // This is a sliding window problem
        // j is left most pointer
        // i is right most pointer
        for (int i = 0; i < s.size(); i++)
        {
            if (myMap.count(s[i]) > 0)
            {
                // the charactor is already there, hence increment J
                j = max(j, myMap[s[i]] + 1);
            }
            //
            res = max(res, i - j + 1);
            myMap[s[i]] = i;
        }
        return res;
    }
};