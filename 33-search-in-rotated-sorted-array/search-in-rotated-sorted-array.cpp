/*class Solution 
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
*/
// Function to return pivot (index of the smallest element)
class Solution 
{
public:

    int findPivot(vector<int> &arr, int lo, int hi) 
    {
        while (lo < hi) {
        
            // The current subarray is already sorted,
            // the minimum is at the low index
            if (arr[lo] <= arr[hi])        
                return lo;
            
            int mid = (lo + hi) / 2;

            // The right half is not sorted. So
            // the minimum element must be in the
            // right half.
            if (arr[mid] > arr[hi])
                lo = mid + 1;
        
            // The right half is sorted. Note that in
            // this case, we do not change high to mid - 1
            // but keep it to mid. The mid element
            // itself can be the smallest
            else
                hi = mid;
        }

        return lo;
    }

    // Searches an element key in a pivoted
    // sorted array arr of size n
    int search(vector<int> &arr, int key) 
    {
        int n = arr.size();
        int pivot = findPivot(arr, 0, n - 1);

        // If we found a pivot, then first compare with pivot
        // and then search in two subarrays around pivot
        if (arr[pivot] == key)
            return pivot;
    
        // If the minimum element is present at index
        // 0, then the whole array is sorted
        if (pivot == 0)
            return binarySearch(arr, 0, n - 1, key);

        if (arr[0] <= key)
            return binarySearch(arr, 0, pivot - 1, key);
        return binarySearch(arr, pivot + 1, n - 1, key);
    }
    int binarySearch(vector<int> &arr, int lo, int hi, int x) 
    {
        while (lo <= hi) 
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == x) 
                return mid;
            if (arr[mid] < x) lo = mid + 1;
                else hi = mid - 1;
        }
        return -1;
    }
};