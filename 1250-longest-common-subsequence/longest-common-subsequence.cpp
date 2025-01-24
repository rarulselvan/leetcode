class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m= text1.size();
        int n= text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
    
        return lcs(text1, text2, m, n, dp);    
    }
    int lcs(string &s1, string &s2, int m, int n, vector<vector<int>> &dp) 
    {
        // Base case: If either string is empty, the length of LCS is 0
        if (m == 0 || n == 0)
            return 0;

        // If the last characters of both substrings match
        if(dp[m-1][n-1] !=-1)
            return dp[m-1][n-1];
            int res=0;

        if (s1[m - 1] == s2[n - 1])
            res= 1 + lcs(s1, s2, m - 1, n - 1, dp);
        else
            res= max(lcs(s1, s2, m, n - 1, dp), lcs(s1, s2, m - 1, n, dp));   

        dp[m-1][n-1]=res;
        return res;
    }
};