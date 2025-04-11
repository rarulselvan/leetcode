class Solution 
{

public:
    // Function to find all the start indices of p's anagrams in s.
    vector<int> findAnagrams(string s, string p)
    {
        int sLen    = s.size();
        int patLen  = p.size();
        vector<int> startingIndices;
      
        // if the length of string s is smaller than the length of string p, no work to do...
        if (sLen < patLen)
            return startingIndices;
      
        // Counters for the characters in p and the current window in s.
        vector<int> patternCount(256, 0);
        
        vector<int> windowCharCount(256, 0);
      
        // Count the occurrences of each character in p.
        for (char c : p) 
            ++patternCount[c]; // Every charactor has a position...
      
        // Get chactors from s of size -1.
        for (int i = 0; i < patLen -1 ; ++i) 
            ++windowCharCount[s[i]];
        
        // Slide the window over string s and compare with character counts of p.
        for (int i = patLen - 1; i < sLen; i++)
        {
            ++windowCharCount[s[i]]; // Add the incoming character into the window count.
            
            // Compare the vector
            if (patternCount == windowCharCount)
                startingIndices.push_back(i - patLen + 1);
            
            // Move the window forward by one: decrease the count of the character leaving the window.
            --windowCharCount[s[i - patLen + 1] ];
        }
        return startingIndices; // Return the collected starting indices of anagrams.
    }
};