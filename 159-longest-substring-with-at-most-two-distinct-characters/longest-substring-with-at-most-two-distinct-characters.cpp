class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(std::string s) 
    {
        unordered_map<char, int> charFrequency;
        int len = s.size();                  
        int maxLength = 0;                       
        int left=0;

        // Two pointers technique, where 'left' is the start of the window and 'right' is the end
        for (int right = 0; right < len; right++) 
        {
            charFrequency[s[right]]++;

            // If our map has more than two distinct characters, shrink the window from the left
            while (charFrequency.size() > 2) 
            {
                charFrequency[s[left]]--; // Decrease the frequency of the leftmost character
                if (charFrequency[s[left]] == 0) // If frequency is zero, remove it from the map
                    charFrequency.erase(s[left]);
                
                ++left; // Move the left boundary of the window to the right
            }

            // Calculate the current length of the substring and update the max length
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength; // Return the length of the longest substring with at most two distinct characters
    }
};
