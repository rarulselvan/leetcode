class Solution 
{
public:
    int maximalRectangle(vector<vector<char>>& mat) 
    {
        int m = mat.size(), n= mat[0].size();

        // 2D matrix to store the width of 1's
        // ending at each cell.
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++) 
            {
                if (mat[i][j] == '0')
                    continue;//ignore '0's
                    

                // Set width of 1's at (i,j).
                if (j == 0)
                    memo[i][0] = 1;
                else
                    memo[i][j] = 1 + memo[i][j - 1];

                int width = memo[i][j];

                // Traverse row by row, update the
                // minimum width and calculate area.
                for (int k = i; k >= 0; k--)
                {
                    width = min(width, memo[k][j]);
                    int area = width * (i - k + 1);

                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};