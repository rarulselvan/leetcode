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

        if(oddCount==0 || oddCount==1)
            return true;
        else
            return false;
    }
};