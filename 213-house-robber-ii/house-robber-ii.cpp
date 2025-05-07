class Solution 
{
      vector<int> memo;
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1) 
            return nums[0];

        vector<int> memo(n, -1);
        int val1 = dfs(nums, n - 2, memo);

        vector<int> subNums(nums.begin() + 1, nums.end());
        vector<int> memo2(n - 1, -1);
        
        int val2 = dfs(subNums, n - 2, memo2); // subNums has size n-1

        return max(val1, val2);
    }

    int dfs(vector<int>& nums, int i, vector<int>& memo) 
    {
        if (i < 0) 
            return 0;

        if (memo[i] != -1) 
            return memo[i];

        return memo[i] = max(dfs(nums, i - 1, memo), nums[i] + dfs(nums, i - 2, memo));
    }
};

/* int robRange(vector<int>& nums, int left, int right) 
    {
        int inclusive = 0; // This will store the max amount including the current house.
        int exclusive = 0; // This will store the max amount excluding the current house.

        // Iterate from the left to the right indices of the house range.
        while (left <= right) 
        {
            int newExclusive = max(inclusive, exclusive);
            inclusive = exclusive + nums[left];
            exclusive = newExclusive;
            left++;
        }
        // Return the maximum of inclusive and exclusive amounts as the result.
        return max(inclusive, exclusive);
    }*/