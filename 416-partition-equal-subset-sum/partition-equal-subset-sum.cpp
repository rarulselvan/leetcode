class Solution
{
    vector<vector<int>> memo;
public:

    bool canPartitionHelper(vector<int>& nums, int i, int target)
    {
        if (target == 0)
            return true;  // Found a valid subset
        if (i < 0 || target < 0) 
            return false; // Out of bounds or invalid target
        
        if (memo[i][target] != -1) 
            return memo[i][target]; // Return memoized result

        // Either include or exclude the current number
        return memo[i][target] = canPartitionHelper(nums, i - 1, target) || 
                                 canPartitionHelper(nums, i - 1, target - nums[i]);
    }

    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false; // If sum is odd, partitioning is impossible
        
        int target = sum / 2;
        memo.assign(nums.size(), vector<int>(target + 1, -1)); // Initialize memo table

        return canPartitionHelper(nums, nums.size() - 1, target);
    }
};