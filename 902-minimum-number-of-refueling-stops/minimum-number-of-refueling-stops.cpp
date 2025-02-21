class Solution
{
public:
    unordered_map<string, int> memo;  // Memoization table

    int dp(int i, int j, vector<vector<int>>& stations, int startFuel) 
    {
        // Base case: No refuel stops
        if (j == 0) return startFuel;
        if (i == 0) return 0;  // No stations left

        // Memoization key
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];

        // Option 1: Skip station `i`
        int maxReach = dp(i - 1, j, stations, startFuel);

        // Option 2: Use station `i` (if we can reach it)
        if (dp(i - 1, j - 1, stations, startFuel) >= stations[i - 1][0]) {
            maxReach = max(maxReach, dp(i - 1, j - 1, stations, startFuel) + stations[i - 1][1]);
        }

        return memo[key] = maxReach;
    }

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        int n = stations.size();
        
        // Try all possible refuel stops
        for (int j = 0; j <= n; j++)
        {
            if (dp(n, j, stations, startFuel) >= target)
                return j;
        }
        
        return -1;
    }
};