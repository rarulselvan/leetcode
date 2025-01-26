class Solution 
{
public:
    int minCoinsRecur(vector<int> &coins, int sum, int i, vector<vector<int>> &dp) 
    {
        // base case
        if (sum == 0) return 0;
        // If sume cannot attached(went to below zero) or tried with all coins retunr -1
        if (sum <0 || i == coins.size())
            return INT_MAX;

        if (dp[i][sum]!=-1) 
            return dp[i][sum];

        int take = -1;

        //Include the coin hence (sum-coin) try with the same coin
        take = minCoinsRecur(coins, sum-coins[i], i,dp);
        if (take != INT_MAX) 
            take++;
        
        // Exclude the coin (hence send the sum as it is) and try with next coin (i+1)
        int noTake = minCoinsRecur(coins,sum, i+1, dp);

        return dp[i][sum] = min(take, noTake);
    }

    int coinChange(vector<int> &coins, int sum)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(sum+1, -1));
        int ans = minCoinsRecur(coins, sum, 0, dp);
        return ans!=INT_MAX?ans:-1;
    }
};