class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size() - 1;
        return binarysearch(nums, 0, len, target);   
    }

    int binarysearch(vector<int>& nums, int low, int high, int target) {
        if (low <= high) {
            int mid = low + (high - low) / 2;

            if (target == nums[mid])
                return mid;  // Return index

            if (nums[low] <= nums[mid]) {  // Left part sorted
                if (nums[low] <= target && target <= nums[mid])
                    return binarysearch(nums, low, mid - 1, target);
                else
                    return binarysearch(nums, mid + 1, high, target);
            }    
            else {  // Right part sorted
                if (nums[mid] <= target && target <= nums[high])
                    return binarysearch(nums, mid + 1, high, target);
                else
                    return binarysearch(nums, low, mid - 1, target);
            }
        }
        return -1;  // Not found
    }
};