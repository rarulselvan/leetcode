class Solution {
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;

        int targetSum = totalSum / k;
        sort(nums.rbegin(), nums.rend());
        
        if (nums[0] > targetSum) return false; // Early termination
        
        vector<int> subsetSums(k, 0);

        std::function<bool(int)> dfs = [&](int index) {
            if (index == nums.size()) return true;

            for (int j = 0; j < k; ++j) {
                if (subsetSums[j] + nums[index] > targetSum) continue;
                if (j > 0 && subsetSums[j] == subsetSums[j - 1]) continue; // Avoid redundant states

                subsetSums[j] += nums[index];
                if (dfs(index + 1)) return true;
                subsetSums[j] -= nums[index];

                if (subsetSums[j] == 0) break; // If we placed in an empty subset and failed, no need to try others.
            }
            return false;
        };

        return dfs(0);
    }
};