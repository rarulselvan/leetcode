class Solution 
{
public:
    vector<int> memo;

    int dfs(vector<int>& nums, int i) 
    {
        if (i >= nums.size()) 
            return 0;
        
        if (memo[i] != -1) 
            return memo[i];
        
        return memo[i] = max(nums[i] + dfs(nums, i + 2), dfs(nums, i + 1));
    }

    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        memo=vector<int>(n, -1);
        return dfs(nums, 0);
    }
};