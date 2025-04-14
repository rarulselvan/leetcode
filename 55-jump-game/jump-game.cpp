/*class Solution
{
    vector<int> dp;
public:
    bool canJump(vector<int>& nums) 
    {
        dp.assign(nums.size(), -1);
        return canJumpDP(nums, 0, nums.size()-1);    
    }
    bool canJumpDP(vector<int>& nums, int start, int end)
    {
        if(start>=end)
            return true;
        if(dp[start] !=-1)
            return dp[start];// -1 .. 0...1

        bool reachEnd=false;
        for(int i=1; i<=nums[start]; i++)
        {
            reachEnd=canJumpDP(nums, start+i, end);
            if(reachEnd==true)
                break;
        }
        dp[start]=reachEnd;
        return reachEnd;
    }
};*/
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int mx = 0;
        for (int i = 0; i < nums.size(); i++) //TRy every index
        {
            if (mx < i)  //if maximum reachable is less than the current then not possible
                return false;
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
};