class Solution 
{
    vector<vector<int>> dp;
public:
    int minCoinsRecur(vector<int> &coins, int sum, int i) 
    {
        // base case
        if (sum == 0) return 0;
        // If sume cannot attached(went to below zero) or tried with all coins retunr -1
        if (sum <0 || i == coins.size())
            return INT_MAX;

        if (dp[i][sum]!=-1) 
            return dp[i][sum];

        int take = 0;

        //Include the coin hence (sum-coin) try with the same coin
        take = minCoinsRecur(coins, sum-coins[i], i);
        if (take != INT_MAX) 
            take++;// the coin is inlcuded hence 1 is added
        
        // Exclude the coin (hence send the sum as it is) and try with next coin (i+1)
        int noTake = minCoinsRecur(coins,sum, i+1);
        // the coin is not inlcuded hence should add nothing here
        
        return dp[i][sum] = min(take, noTake);
    }

    int coinChange(vector<int> &coins, int sum)
    {
        dp.assign(coins.size(), vector<int>(sum+1, -1));
        int ans = minCoinsRecur(coins, sum, 0);
        return ans!=INT_MAX?ans:-1;
    }
};

/*
class Solution 
{
private:
    
public:
  
    int coinChange(vector<int> &coins, int sum)
    {
        int res=INT_MAX;
        int subRes=0;
        vector<int> dp(sum + 1, -2); // -2 = uncomputed, -1 = impossible
        function<int(int)>dfs;
        dfs=[&](int sum)
        {
            if (sum < 0) 
                return -1;
            if (sum == 0)
                 return 0;
            if (dp[sum] != -2) 
                return dp[sum];

            int min_coins = INT_MAX;
            for (int coin : coins) 
            {
                int res = dfs(sum - coin);
                if (res >= 0 && res < min_coins)
                    min_coins = res + 1;
            }

            dp[sum] = (min_coins == INT_MAX) ? -1 : min_coins;
            return dp[sum];
        };
        return dfs(sum);
    }
};
*/