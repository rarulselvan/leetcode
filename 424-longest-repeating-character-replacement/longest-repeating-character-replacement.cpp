class Solution 
{
public:
    int characterReplacement(string s, int k) 
    {
        vector<int> charCount(256, 0);
        int left = 0;
        int right = 0;
        int maxCharCount = 0;
      
        for (right = 0; right <s.size(); right++)
        {
            charCount[s[right]]++; // Increment the count for the current character

            // Update the max frequency character count seen so far in the current window
            maxCharCount = max(maxCharCount, charCount[s[right]]);
          
            // Check if the current window size minus the count of the max frequency character
            // is greater than k, if so, shrink the window from the left
            if (right - left + 1 - maxCharCount > k)
             {
                charCount[s[left]]--; // Decrement the count for the character at the left index as it's going out of the window
                left++; // Shrink the window from the left
            }
        }

        // The length of the largest window compliant with the condition serves as the answer
        return right - left;
    }
};