class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int size = nums.size();
        int left = 0, right = size - 1;

        while (left < right) 
        {
            int mid = left + (right - left) / 2; // Avoids potential overflow compared to (left + right) >> 1

            // Determine the side of the rotated sequence 'mid' is on
            if (nums[0] <= nums[mid]) 
            {
                // 'mid' is in the left (non-rotated) part of the array
                if (nums[0] <= target && target <= nums[mid]) 
                {
                    // Target is within the left (non-rotated) range, search left side
                    right = mid;
                } 
                else 
                {
                    // Search right side
                    left = mid + 1;
                }
            }
            else
            {
                // 'mid' is in the right (rotated) part of the array
                if (nums[mid] < target && target <= nums[size - 1]) {
                    // Target is within the right (rotated) range, search right side
                    left = mid + 1;
                } else {
                    // Search left side
                    right = mid;
                }
            }
        }

        // The final check to see if the target is found at 'left' index
        return (left == right && nums[left] == target) ? left : -1;
    }
};
