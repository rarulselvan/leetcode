class Solution 
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> charCount(256, 0); // For uppercase English letters (A-Z)
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int maxCharCount = 0;

        for (right = 0; right < s.size(); right++)
        {
            charCount[s[right]]++;
            maxCharCount = max(maxCharCount, charCount[s[right]]);

            // Shrink if replacements needed exceed k
            if (right - left + 1 - maxCharCount > k)
            {
                charCount[s[left]]--;
                left++;
            }
            else
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};