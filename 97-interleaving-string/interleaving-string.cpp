class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int  m = s1.size();
        int  n = s2.size();

        if (m+n != s3.size())//no point in further calculation
            return false;
        
    
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        function<bool(int, int)>dfs;

        dfs = [&](int i, int j) 
        {
            if (i >= m && j >= n) //if both charctor streams are exhausted return true
                return true;
            
            if (dp[i][j] != -1)
                return dp[i][j] == 1;
            
            dp[i][j] = 0;

            int k = i + j;

            if (i < m && s1[i] == s3[k] && dfs(i + 1, j)) 
                dp[i][j] = 1;
            
            else if(j < n && s2[j] == s3[k] && dfs(i, j + 1)) 
                dp[i][j] = 1;
            
            return dp[i][j] == 1;
        };
        return dfs(0, 0); //start from the beginning
    }
};