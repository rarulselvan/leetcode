class Solution 
{
public:
    int characterReplacement(string s, int k)
    {
       // vector<int> charCount(256, 0); // For uppercase English letters (A-Z)
        unordered_map<char, int>charCount;
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int maxCharCount = 0;

        for (right = 0; right < s.size(); right++)
        {
            charCount[s[right]]++;
            maxCharCount = max(maxCharCount, charCount[s[right]]);

            int windowsSize=right-left+1;
            if (windowsSize - maxCharCount > k)//we can only replace k charactors to the max occured charactor in the window
            {
                // Shrink if replacements needed exceed 'k'
                charCount[s[left]]--;
                left++;
            }
            else//calculate the max length on cases no need to shrink the window
                maxLen = max(maxLen, windowsSize);
        }
        return maxLen;
    }
};