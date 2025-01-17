class Solution 
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> myMap;
        int res = 0;
        int j = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (myMap.count(s[i]) > 0)
            {
               j = max(j, myMap[s[i]] + 1);
            }
            res = max(res, i - j + 1);
            myMap[s[i]] = i;
        }
        return res;
    }
};