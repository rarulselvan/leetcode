// Function to find the number of unique paths from (0,0) to (m-1,n-1)
int findPaths(int** grid, int m, int n, int i, int j, int** dp)
{
    // If out of bounds or there's an obstacle, return 0
    if (i >= m || j >= n || grid[i][j] == 1) 
    {
        return 0;
    }

    // If reached the bottom-right corner, return 1
    if (i == m - 1 && j == n - 1) 
    {
        return 1;
    }

    // If already calculated, return the stored value
    if (dp[i][j] != -1) 
    {
        return dp[i][j];
    }

    // Calculate the number of paths by moving right and down
    int rightPaths = findPaths(grid, m, n, i, j + 1, dp);
    int downPaths = findPaths(grid, m, n, i + 1, j, dp);

    // Store the result in the memoization table and return it
    return dp[i][j] = rightPaths + downPaths;
}

int uniquePathsWithObstacles(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    // Allocate memory for memoization table and initialize it to -1
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        dp[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) 
        {
            dp[i][j] = -1;
        }
    }

    // Call the recursive function starting from (0,0)
    int result = findPaths(grid, m, n, 0, 0, dp);

    // Free the memoization table
    for (int i = 0; i < m; i++) 
        free(dp[i]);    
    free(dp);

    return result;
}
