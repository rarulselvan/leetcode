class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        int totalCount = 0;

        function<bool(int,int)> dfs;
        dfs=[&](int i, int j)->bool
        {
            if (i >= j) return true; // base case
            if (dp[i][j] != -1) 
                return dp[i][j];

            if (s[i] == s[j]) {
                return dp[i][j] = dfs(i+1, j-1);
            }
            return dp[i][j] = false;
        };

        // check all substrings
        for (int i = 0; i < n; i++) 
        {
            for (int j = i; j < n; j++) 
            {
                if (dfs(i, j)) 
                    totalCount++;
            }
        }
        return totalCount;
    }
};