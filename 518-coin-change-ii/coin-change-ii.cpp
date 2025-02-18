class Solution 
{
private:
    vector<vector<int>> dp; // Memoization tablepublic:

public:
    int changeDP(int i, int amount, vector<int>& coins) 
    {
        if (amount == 0) 
            return 1;  // Found a valid combination
        if (i >= coins.size() || amount < 0)
            return 0;  // Invalid case

        if (dp[i][amount] != -1) 
            return dp[i][amount]; // Return cached result

        // Include current coin OR skip to next coin
        return dp[i][amount] = changeDP(i, amount - coins[i], coins) + changeDP(i + 1, amount, coins);
    }

    int change(int amount, vector<int>& coins) 
    {
        dp.assign(coins.size(), vector<int>(amount + 1, -1)); // Initialize DP table
        return changeDP(0, amount, coins); // Start recursion from index 0
    }
};