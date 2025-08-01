class Solution 
{
    vector<vector<int>> dp;
    public:

        int minDisRec(string& s1, string& s2, int m, int n)
        {
            if (m == 0) return n;

            if (n == 0) return m;

            if (dp[m][n] != -1) return dp[m][n];

            if (s1[m - 1] == s2[n - 1]) 
                dp[m][n] = minDisRec(s1, s2, m - 1, n - 1);
            
            else 
            {
                dp[m][n] = 1 + min({
                    minDisRec(s1, s2, m, n - 1),    // Insert
                    minDisRec(s1, s2, m - 1, n),    // Remove
                    minDisRec(s1, s2, m - 1, n - 1) // Replace
                });
            }

            return dp[m][n]; // Return the computed minimum distance
    }

    // Function to initialize memoization table and start the recursive function
    int minDistance(string s1, string s2) 
    {
        int m = s1.length(), n = s2.length();
        //vector<vector<int>> dp  (m + 1, vector<int>(n + 1, -1));
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return minDisRec(s1, s2, m, n);
    }

};