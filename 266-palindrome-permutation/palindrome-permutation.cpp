class Solution 
{
public:
    bool canPermutePalindrome(string s) 
    {
        unordered_map<char, int> charCounts;

        for (char c : s) 
            charCounts[c]++;
        
        int oddCount = 0;

        for (auto& [key, count]: charCounts) 
        {
            // If the count is odd, increment the odd count
            oddCount += count % 2; // Count is odd if % 2 is 1
        }

        // one oddcount  A string can be permuted to form a palindrome if there is at most one character with an odd count
        return oddCount < 2;
    }
};