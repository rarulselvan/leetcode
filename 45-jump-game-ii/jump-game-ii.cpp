class Solution 
{
private:
    vector<int>dp;
public:
    int jump(vector<int>& nums)
    {
        dp.assign(nums.size() + 1, -1);
        return  jumpDP(nums, 0, nums.size()-1);
    }
    int jumpDP(vector<int>& nums, int start, int end)
    {
        // Base case.. wec ould able to reach the end of array .. hence this is a valid path
        if (start >= end)
            return 0;

        if (dp[start] != -1)
            return dp[start];

        int result = INT_MAX;

        for (int i = 1; i <= nums[start]; i++)  // These many locations can be reached...
        {
            int minJumps = jumpDP(nums, start + i, end);
            if (minJumps != INT_MAX) // Fix: Prevent overflow when adding 1
                result = min(result, 1 + minJumps); //get the minimum value 
        }
        // at times nums[start] is zero "INT_MAX" will be returned
        dp[start] = result;
        return result;
    }
};