class Solution
{
public:
    int findMin(vector<int>& nums) 
    {
        int n = nums.size();
        
        //case1: array not rotated or rotated n times
        if (nums[0] <= nums[n - 1]) 
            return nums[0];
        //Two pointer
        int left = 0, right = n - 1;
        while (left < right) 
        {
            int mid = (left + right)/ 2;
            if (nums[0] <= nums[mid])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};