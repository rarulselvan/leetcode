class Solution
{
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> Map;
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j)
                Map[mat[i][j]] = {i, j};//This map stores each value of mat along with its position (row, column).
        }
        vector<int> row(m);
        vector<int> col(n);
        for (int k = 0;; k++)
        {
            auto [i, j] = Map[arr[k]];
            //row[i] keeps track of how many elements in row i have been seen.
            //col[j] keeps track of how many elements in column j have been seen.
            ++row[i];
            ++col[j];
            if (row[i] == n || col[j] == m) 
                return k;
        }
    }
};