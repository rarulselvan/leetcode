class Solution 
{
private:
    vector<int> dp;
public:    
    int dfs(vector<int>& nums, int target) 
    {
        if(target==0)
            return 1;
        if(dp[target] !=-1)
            return dp[target];
        int count=0;
        for(int x:nums)
        {
            if(x<=target)
                count=count+dfs(nums,target-x);
            else
                continue; //try the next element
        }
        return dp[target] = count; // Store result
    }

    int combinationSum4(vector<int>& nums, int target) 
    {
        dp=vector(target+1, -1);
        return dfs(nums, target);
    }
};