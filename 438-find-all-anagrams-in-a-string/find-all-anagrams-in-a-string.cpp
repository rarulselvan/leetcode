/*
class Solution 
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        vector<int> ans;

        // sort the p(attern) and store it
        string sortedp = p;
        sort(sortedp.begin(), sortedp.end());

        for (int i = 0; i <= (m-n); i++)
        {
            string temp = "";
            // temp stores the every substring of length m
            for (int k = i; k <n+ i; k++)
              temp.push_back(s[k]);
            sort(temp.begin(), temp.end());
            // checking sorted version of substring equal to sorted P are not
            if (temp == sortedp)
            ans.push_back(i);
        }
        return ans;
    }
};*/

class Solution 
{

public:
    // Function to find all the start indices of p's anagrams in s.
    vector<int> findAnagrams(string s, string p)
    {
        int sLength = s.size();
        int pLength = p.size();
        vector<int> startingIndices; // Holds the starting indices of anagrams.
      
        // Base case: if the length of string s is smaller than the length of string p,no anagrams of p can be found in s.
        if (sLength < pLength)
            return startingIndices;
      
        // Counters for the characters in p and the current window in s.
        vector<int> patternCount(256, 0); // Assuming only lowercase English letters.
        
        vector<int> windowCharCount(256, 0);
      
        // Count the occurrences of each character in p.
        for (char c : p) 
          //  ++patternCount[c - 'a']; // Increment the count for this character.
          ++patternCount[c ]; // Increment the count for this character.
      
        // Initialize windowCharCount with the first window in s.
        for (int i = 0; i < pLength - 1; ++i) 
            //++windowCharCount[s[i] - 'a'];
            ++windowCharCount[s[i]];
        
      
        // Slide the window over string s and compare with character counts of p.
        for (int i = pLength - 1; i < sLength; ++i)
        {
            //++windowCharCount[s[i] - 'a']; // Add the current character to the window count.
            ++windowCharCount[s[i]]; // Add the current character to the window count.
          
            // If the window has the same character counts as p, it's an anagram starting at (i - pLength + 1).
            if (patternCount == windowCharCount)
                startingIndices.push_back(i - pLength + 1);
          
            // Move the window forward by one: decrease the count of the character leaving the window.
            //--windowCharCount[s[i - pLength + 1] - 'a'];
            --windowCharCount[s[i - pLength + 1] ];
        }
        return startingIndices; // Return the collected starting indices of anagrams.
    }
};