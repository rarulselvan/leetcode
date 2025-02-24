class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
       // if (numRows == 0) return {}; // Handle edge case
        
        //matrix of square is created
        vector<vector<int>> f(numRows);
        for (int i = 0; i < numRows; ++i) 
        {
            f[i].resize(i + 1, 1); // Resize and fill with 1s
            
            for (int j = 1; j < i; ++j)
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            
        }
        return f;
    }
};