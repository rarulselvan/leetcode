class Solution 
{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();    
        int cols = matrix[0].size(); 
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int longestPath = 0;
        // Directions array representing the four possible movements (up, right, down, left)
        vector<int> directions = {-1, 0, 1, 0, -1};

        // Depth-first search function to find the longest increasing path
        function<int(int, int)> dfs = [&](int row, int col)
        {
            // If answer exists in memo table.
            if (dp[row][col] != -1)
                return dp[row][col];

            // include current cell in answer
            int ans = 1;

            // direction vector to move in 4 directions
            vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for (vector<int> d : dir) 
            {
                int x = row + d[0], y = col + d[1];

                if (x < 0 || x >= rows || y < 0 || y >= cols)//boundary case skip this
                    continue;

                if (matrix[x][y] > matrix[row][col])//IN all four directions ..the direction from where we reached this location will fail always
                {
                    ans = max(ans, 1 + dfs(x, y));
                }
            }
            // Memoize the answer and return it.
            return dp[row][col] = ans;
        };

        // Iterate through each cell in the matrix
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j) 
                longestPath = max(longestPath, dfs(i, j));
        }
        // Return the length of the longest path after processing all cells
        return longestPath;
    }
};