class Solution 
{
    vector<vector<int>>dp;
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        dp.assign(m, vector<int>(n, -1));
        return minPathSumDP(grid, m-1, n-1);
    }
    int minPathSumDP(vector<vector<int>> &mat, int m, int n)
    {
        if(m==0 && n==0)
             return mat[m][n];
        if(m<0 || n<0)
            return 0xFFFFFF;

        if(dp[m][n] !=-1)
            return dp[m][n];
        dp[m][n] =  mat[m][n] + min(minPathSumDP(mat, m-1, n), minPathSumDP(mat,m, n-1));
        return dp[m][n];
    }
};