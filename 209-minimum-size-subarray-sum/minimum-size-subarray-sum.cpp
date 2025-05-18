class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();              
        int sum = 0;                
        int ans = n + 1;     
        int left=0;

        // Two pointers, left and right
        for (int right = 0; right < n; right++) 
        {
            sum = sum + nums[right];               // Increase the sum by the current element
          
            // While sum is not smaller than the target and start pointer 'j' has not reached the end
            while (sum >= target) 
            {
                ans = min(ans, (right - left)); // Update the answer with the new minimum length
                sum =sum-nums[left]; //remove the left pointer
                left++;  // Subtract the first element of the subarray and move the left pointer
            }
        }
      
        // If 'ans' didn't change, no valid subarray was found, return 0 ...Otherwise, return the length of the shortest subarray
        return ans == n + 1 ? 0 : ans+1;//(0....ans so ans+1)
    }
};