class Solution 
{
    vector<vector<int>>dp;
public:

    int uniquePaths(int m, int n) 
    {
        dp.assign(m, vector<int>(n, -1));  // initialize dp table with -1
        return uniquePathsDP(m - 1, n - 1);
    }
    int uniquePathsDP(int m, int n) 
    {
        if(m==0)
            return 1;
        if(n==0)
            return 1;

        if(dp[m][n] !=-1)
            return dp[m][n];
        
        dp[m][n]=uniquePathsDP(m-1, n)+uniquePathsDP(m, n-1);
        return dp[m][n];
    }
};
/*
class Solution 
{
    vector<vector<int>> dp;
public:
    int uniquePaths(int m, int n) 
    {
        dp.assign(m, vector<int>(n, -1));  // initialize dp table with -1
        return uniquePathsDP(m - 1, n - 1);
    }

private:
    int uniquePathsDP(int i, int j) 
    {
        if (i == 0 || j == 0)
            return 1;  // base case: only one way along the edge

        if (dp[i][j] != -1)
            return dp[i][j];

        // memoized recursion
        dp[i][j] = uniquePathsDP(i - 1, j) + uniquePathsDP(i, j - 1);
        return dp[i][j];
    }
};*/