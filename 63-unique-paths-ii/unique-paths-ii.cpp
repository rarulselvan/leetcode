class Solution
{
private:
    vector<vector<int>>dp;
    int m;
    int n;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<int>(n,-1));

        // Call the recursive function starting from (0,0)
        int result = findPaths(grid, 0, 0);

        return result;
    }

    int findPaths(vector<vector<int>> &grid, int i, int j)
    {
        // If out of bounds or there's an obstacle, return 0
        if (i >= m || j >= n || grid[i][j] == 1) 
            return 0;
        
        // If reached the bottom-right corner, return 1
        if (i == m - 1 && j == n - 1) 
            return 1;

        // If already calculated, return the stored value
        if (dp[i][j] != -1) 
            return dp[i][j];

        // Calculate the number of paths by moving right and down
        int rightPaths = findPaths(grid, i, j + 1);
        int downPaths = findPaths(grid, i + 1, j);

        // Store the result in the memoization table and return it
        return dp[i][j] = rightPaths + downPaths;
    }

};