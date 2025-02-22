class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int numberOfStrings = strs.size(); // Total number of strings in the vector.
      
        // Loop over the characters of the first string.
        for (int charIndex = 0; charIndex < strs[0].size(); ++charIndex) 
        {
            // Compare the current character with the same position in each subsequent string.
            for (int strIndex = 1; strIndex < numberOfStrings; ++strIndex) 
            {
                // Check if the current character index exceeds the length of the current string
                // or the characters do not match.
                if (strs[strIndex].size() <= charIndex || strs[strIndex][charIndex] != strs[0][charIndex]) 
                {
                    // Return the longest common prefix found so far.
                    return strs[0].substr(0, charIndex);
                }
            }
        }
      
        // If we reach this point, it means the first string is a common prefix for all strings in the array.
        // Thus, simply return the first string.
        return strs[0];
    }
};