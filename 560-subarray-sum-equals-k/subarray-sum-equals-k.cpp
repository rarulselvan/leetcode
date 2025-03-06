class Solution 
{
public:
     int subarraySum(vector<int>& nums, int k) 
     {
        unordered_map<int, int> map;  // HashMap to store cumulative sum frequencies
        map[0] = 1;  // The first number may be equal to k ...hence this is required
        
        int count = 0, sum = 0;

        for (int num : nums) 
        {
            sum += num;
            //count += map[sum - k];  // Add count of subarrays that sum to k
            cout <<sum<<" ";
            if(map[sum-k])
               count += map[sum - k];
            map[sum]++;  // Update frequency of cumulative sum
        }
    
        return count;
    }
};
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int target) 
    {
        int left = 0, sum = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];  // Expand the window
                        // If the sum matches the target, increase the count
           
            // Shrink the window from the left if sum exceeds target
            while (left < right && sum > target) {
                sum -= nums[left];
                left++;
            }

            // If the sum matches the target, increase the count
            if (sum == target) {
                count++;
            }
        }
        return count;
    }
}; */