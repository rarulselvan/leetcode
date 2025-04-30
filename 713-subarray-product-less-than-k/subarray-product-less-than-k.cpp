class Solution 
{
public:

    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int count = 0;
        int product=1;
        int left=0;
        int right=0;

        while(right < nums.size())
        {
            product = product*nums[right];

            while (product >= k && left <= right) 
                product = product/nums[left++];

            //Get the size of the current window
            count += right - left + 1;
            
            right++;
        }
      
        // Return the total count
        return count;
    }
};