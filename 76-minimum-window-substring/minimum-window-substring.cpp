
/*class Solution {
public:
    string minWindow(string s, string t)
     {
        int need[128] = {0}; // Array to store the frequency of characters required from 't'
        int window[128] = {0}; // Array to store the frequency of characters in the current window
        int strLength = s.size();
        int targetLength = t.size();
      
        // Populate the need array with frequencies of characters in 't'
        for (char& c : t)
            need[c]++;
        
        // Initialize variables for the sliding window technique
        int matches = 0; // Number of characters that match 't' in the current window
        int start = 0; // Start index of the minimum window
        int minStart = -1; // Start index of the overall minimum window found
        int minLength = INT_MAX; // Length of the overall minimum window found
      
        // Iterate over the string 's' using 'i' as the end index of the window
        for (int i = 0; i < strLength; ++i) {
            // Include the character at the current position into the window
            ++window[s[i]];
            // If the current character is needed and the window contains enough
            // instances of it to match 't', then increment the match count
            if (need[s[i]] >= window[s[i]]) {
                ++matches;
            }
            // When all characters from 't' are found in the current window
            while (matches == targetLength) {
                // Update minimum window if the current window's length is smaller
                if (i - start + 1 < minLength) {
                    minLength = i - start + 1;
                    minStart = start;
                }
                // Exclude character at the start position from the window
                if (need[s[start]] >= window[s[start]]) {
                    --matches;
                }
                --window[s[start++]];
            }
        }
      
        // If no window was found, return an empty string. Otherwise, return the minimum window
        return minStart < 0 ? "" : s.substr(minStart, minLength);
    }
};
*/
class Solution 
{
public:
    string minWindow(string s, string t) 
    {        
        unordered_map<char, int> tFreq;
        unordered_map<char, int> windowFreq;
        
        // Count the frequency of characters in t
        for (char c : t) 
            tFreq[c]++;
        
        int required = tFreq.size();  // Number of unique characters needed
        int formed = 0;               // Number of unique chars matched in the window
        
        int left = 0, right = 0;
        int minLen = INT_MAX, startIdx = 0;
        
        while (right < s.length()) 
        {
            char c = s[right];
            windowFreq[c]++;
            
            // If this character is part of `t` and count matches
            if (windowFreq[c] == tFreq[c])
                formed++;
            
                // slide the window
                while (formed == required && left <= right)
                {
                    char leftChar = s[left];

                    // Update the smallest window found
                    if (right - left + 1 < minLen) 
                    {
                        minLen = right - left + 1;
                        startIdx = left;
                    }

                    // Remove from the window
                    windowFreq[leftChar]--;
                    if (tFreq.count(leftChar) && windowFreq[leftChar] < tFreq[leftChar])
                        formed--;

                    left++;  // Shrink window
                }

            right++;  // Expand window
        }
        
        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
