class Solution 
{
    vector<vector<int>>memo;
public:
    int getMaxCoins(int left, int right, vector<int> &arr)
    {
        // If no balloons in this range, return 0
        if (left > right) return 0;

        // If the result is already computed, return it
        if (memo[left][right] != -1) return memo[left][right];

        int maxCoins = 0;

        // Try each balloon `k` in range [left, right] 
        // as the last balloon to burst
        for (int k = left; k <= right; k++)
        {
            // Calculate coins from bursting `k` last in this range
            int coins = arr[left - 1] * arr[k] * arr[right + 1];

            // Recursively compute coins from the left and 
            // right subarrays
            int leftCoins = getMaxCoins(left, k - 1, arr);
            int rightCoins = getMaxCoins(k + 1, right, arr);

            // Update maxCoins with the best option
            maxCoins = max(maxCoins, coins + leftCoins + rightCoins);
        }

        // Store the result in the memoization table
        memo[left][right] = maxCoins;

        return maxCoins;
    }

    // Max coin computation
    int maxCoins(vector<int> &arr)
    {
        int n = arr.size();
        // Add virtual balloons with value 1 at both ends of `arr`
        arr.insert(arr.begin(), 1);
        arr.push_back(1);

        // Create a memoization table initialized to -1//n+2 is required because we added two elements extra (one in the begining..other in the end)
        memo.assign(n + 2, vector<int>(n + 2, -1));

        // Call the recursive helper
        return getMaxCoins(1, n, arr);
    }
};