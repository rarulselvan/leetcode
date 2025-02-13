/*class Solution {
public:
    string longestPalindrome(string &s) 
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromes
        int maxLen = 1;
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;

        // Check for sub-string of length 2
        int start = 0;
        for (int i = 0; i < n - 1; ++i) 
        {
            if (s[i] == s[i + 1]) 
            {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check for lengths greater than 2
        for (int k = 3; k <= n; ++k) 
        {
            for (int i = 0; i < n - k + 1; ++i) 
            {
                int j = i + k - 1;

                if (dp[i + 1][j - 1] && s[i] == s[j]) 
                {
                    dp[i][j] = true;

                    if (k > maxLen) 
                    {
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
}
};
*/
class Solution 
{
public:
    string s;
    vector<vector<int>> memo;

    bool isPalindrome(int i, int j) 
    {
        if (i >= j) return true;
        if (memo[i][j] != -1) return memo[i][j];
        
        return memo[i][j] = (s[i] == s[j] && isPalindrome(i + 1, j - 1));
    }

    string longestPalindrome(string &str) 
    {
        s = str;
        int n = s.size();
        memo.assign(n, vector<int>(n, -1));
        
        int start = 0, maxLen = 1;
        
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i; j < n; ++j) 
            {
                if (isPalindrome(i, j) && (j - i + 1) > maxLen) 
                {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }      
        return s.substr(start, maxLen);
    }
};