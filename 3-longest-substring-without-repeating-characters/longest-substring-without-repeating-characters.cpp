
class Solution 
{
public:
    int lengthOfLongestSubstring(string& s) 
    {
        int len=0;
        int left=0;
        int right=0;
        unordered_map<char, int>Map;
        
        for(right=0; right<s.size(); right++)
        {
            Map[s[right]]++;
            while(Map[s[right]]>1)
            {
                Map[s[left]]--;
                left++;
            }
            len=max(len, right-left+1);
        }
        return len;
    }
};
