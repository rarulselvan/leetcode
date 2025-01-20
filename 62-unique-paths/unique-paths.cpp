class Solution 
{
public:
    int uniquePathsDP(int m, int n, vector<vector<int>> &dp) //receive as reference
    {
        if(m==0)
            return 1;
        if(n==0)
            return 1;
        if(dp[m][n] !=-1)
            return dp[m][n];

        dp[m][n]=uniquePathsDP(m-1, n, dp)+uniquePathsDP(m, n-1, dp);
        return dp[m][n];
    }
    int uniquePaths(int m, int n) 
    {
        vector<int> row(n+1, -1);
	    // Initializing the 2-D vector
	    vector<vector<int>> dp(m+1, row);

        return uniquePathsDP(m-1, n-1, dp);
    }
};