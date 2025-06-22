
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int maxReachable = 0;
        for (int i = 0; i < nums.size(); i++) //TRy every index
        {
            if (maxReachable < i)  //if maximum reachable is less than the current then not possible
                return false;
            maxReachable = max(maxReachable, i + nums[i]);
        }
        return true;
    }
};