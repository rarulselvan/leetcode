class Solution 
{
    int res = 0;
    vector<vector<int>> dp; // Memoization table:
public:
    int change(int amount, vector<int>& coins) 
    {
        dp.assign(coins.size(), vector<int>(amount + 1, -1)); // Initialize DP table
        function<int(int, int)> dfs;
        dfs = [&](int sum, int start) 
        {
            if (sum == 0) 
                return 1;
            if (sum < 0)
                return 0;
            if (dp[start][sum] != -1) //for thsi starting position and sum..if the result is already computed ..simply use it
                return dp[start][sum];

            int ways = 0;
            for (int i = start; i < coins.size(); i++)
            {
                ways=ways + dfs(sum - coins[i], i); // Use coin[i] again, so pass i
            }
            return dp[start][sum] = ways;
           // return ways;
        };
       return dfs(amount, 0);
    }
};