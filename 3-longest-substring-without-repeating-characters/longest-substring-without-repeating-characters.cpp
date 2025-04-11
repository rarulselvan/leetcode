class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        // This unordered set is used to store the characters that are currently in the
        // longest substring without repeating characters.
        unordered_set<char> slidingSet;

        // The starting index of the substring.
        int start = 0;
        int maxLength = 0;

        for (int end = 0; end < s.size(); end++) 
        {
            // If the character at the current ending index of the substring already exists
            // in the character set, continue to remove characters from the start of the
            // substring until the character is no longer in the set.
            while (slidingSet.count(s[end])) 
            {
                slidingSet.erase(s[start]);
                start += 1;
            }

            // Insert the current character into the set.
            slidingSet.insert(s[end]);

            int currLength=slidingSet.size();
            maxLength = max(maxLength, currLength);
        }
        // Return the length of the longest substring found.
        return maxLength;
    }
};