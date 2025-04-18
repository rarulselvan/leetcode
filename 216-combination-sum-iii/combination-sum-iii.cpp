class Solution 
{
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int, int)> dfs;
        dfs= [&](int i, int sum, int count) 
        {
            if (sum == 0 && count == k) 
            {
                ans.push_back(path);
                return;
            }
            if (sum < 0 || count > k) 
                return;

            for (int j = i; j<= 9; j++) 
            {
                path.push_back(j);
                dfs(j + 1, sum - j, count + 1);
                path.pop_back();
            }
        };
        dfs(1, n, 0);
        return ans;
    }
};