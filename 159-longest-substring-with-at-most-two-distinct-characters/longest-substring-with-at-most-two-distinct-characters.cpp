class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        unordered_map<char, int> charFrequency;
        int len = s.size();                  
        int maxLength = 0;                       
        int left=0;

        // Two pointers technique, where 'left' is the start of the window and 'right' is the end
        for (int right = 0; right < len; right++) 
        {
            charFrequency[s[right]]++;

            while (charFrequency.size() > 2) 
            {
                if(charFrequency[s[left]])
                charFrequency[s[left]]--;
                if (charFrequency[s[left]] == 0) // is required to remove key-value pairs when the frequency of a key reaches zero, even if the value is still present in the map.
                   charFrequency.erase(s[left]);
                
                ++left;
            }

            // Calculate the current length of the substring and update the max length
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
