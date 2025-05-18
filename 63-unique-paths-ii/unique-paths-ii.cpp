class Solution 
{
vector<vector<int>>dp;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
        dp.assign(m, vector<int>(n, -1));
        return uniquePathsWithObstaclesDP(mat,m-1, n-1);
    }
    int uniquePathsWithObstaclesDP(vector<vector<int>>mat, int m, int n)
    {
        if(m>=0 && n>=0 && mat[m][n]==1)
            return 0;
        
        if(m==0 && n==0)
            return 1;

        if(m<0|| n <0)
            return 0;

        if(dp[m][n] !=-1)
            return dp[m][n];

        dp[m][n]=uniquePathsWithObstaclesDP(mat,m-1,n) + uniquePathsWithObstaclesDP(mat,m,n-1);
        return dp[m][n];
    }
};