/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
        if (l == r)
        {
            return {-1, -1};
        }
        return {l, r - 1};
    }
};
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left = findLowerBound(nums, 0, nums.size() - 1, target);
        int right = findUpperBound(nums, 0, nums.size() - 1, target);
        return {left, right};
    }

    int findLowerBound(vector<int>& nums, int low, int high, int target) 
    {
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target)) 
                return mid;
            else if (nums[mid] < target) 
                low = mid + 1;
            else 
                high = mid - 1;
            
        }
        return -1;
    }

    int findUpperBound(vector<int>& nums, int low, int high, int target) 
    {
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] > target))
                return mid;
            else if (nums[mid] <= target) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }
};
