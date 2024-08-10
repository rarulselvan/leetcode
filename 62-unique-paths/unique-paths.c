int uniquePathsDP(int m, int n, int **dp) 
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
    int **dp = (int **)malloc((m) * sizeof(int *));
    for (int i = 0; i < m; i++) 
    {
        dp[i] = (int *)malloc((n) * sizeof(int));
    }
    for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
        dp[i][j]=-1;
    
    return uniquePathsDP(m-1, n-1, dp);
}