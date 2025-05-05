
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

/*
class Solution 
{
public:
    int lengthOfLongestSubstring(string& s) 
    {
        int res = 0;
        unordered_map<char, int>Map;
        int left = 0; 
        int right = 0;

        for(right=0; right < s.length(); right++)
        {
            while (Map[s[right]])  //If the charactor is already available move the left pointer
            {
                Map[s[left]]--;
                left++;
            }
            //Now add the charactor into map
            Map[s[right]]++;

            // The length of the current window (right - left + 1) is calculated and answer is updated accordingly.
            res = max(res, (right - left + 1));
        }
        return res;
    }
};*/