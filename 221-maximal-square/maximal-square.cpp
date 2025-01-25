class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        // Get the number of rows and coloumn size
        int rows = matrix.size();
        int cols = matrix[0].size();
      
        // Create a 2D DP (dynamic programming) table with an extra row and column set to 0.
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
      
        int maxSize = 0; // Initialize the maximum square size found to 0.
      
        // Iterate through the matrix, starting from the top-left corner.
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j)
            {
                // If the current element is '1', calculate the size of the square.
                if (matrix[i][j] == '1') 
                {
                    // The size of the square ending at (i, j) is the minimum of the three
                    // neighboring squares plus 1.
                    dp[i + 1][j + 1] = min(min(dp[i][j + 1], dp[i + 1][j]), dp[i][j]) + 1;
                    // Update the maximum size found so far.
                    maxSize = max(maxSize, dp[i + 1][j + 1]);
                }
            }
        }
        // Return the area of the largest square found.
        return maxSize * maxSize;
    }
};
