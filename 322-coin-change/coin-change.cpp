class Solution 
{
public:
    int minCoinsRecur(int i, int sum, vector<int> &coins, vector<vector<int>> &memo) 
    {
        // base case
        if (sum == 0) return 0;
        if (sum <0 || i == coins.size()) return INT_MAX;

        if (memo[i][sum]!=-1) 
            return memo[i][sum];

        int take = INT_MAX;

        // take a coin only if its value
        // is greater than 0.
        if (coins[i]>0) 
        {
            take = minCoinsRecur(i, sum-coins[i], coins, memo);
            if (take != INT_MAX) take++;
        }

        int noTake = minCoinsRecur(i+1, sum, coins, memo);

        return memo[i][sum] = min(take, noTake);
    }

    int coinChange(vector<int> &coins, int sum)
    {
        vector<vector<int>> memo(coins.size(), vector<int>(sum+1, -1));
        int ans = minCoinsRecur(0, sum, coins, memo);
        return ans!=INT_MAX?ans:-1;
    }
};