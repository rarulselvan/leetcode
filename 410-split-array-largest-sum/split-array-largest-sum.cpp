class Solution {
public:
    int splitArray(vector<int>& nums, int k)
    {
        // Initialize the bounds for binary search.
        int minMax = 0, sum = 0;
        // Calculate the largest number in nums as the lower bound and the sum for the upper bound.
        for (int num : nums) 
        {
            minMax = max(minMax, num);
            sum += num;
        }
      
        // Lambda function to check if it's possible to split the array into at most 'k' parts with max sum 'maxSum'.
        auto canSplit = [&](int maxSum) 
        {
            int cumulativeSum = 0, parts = 1;
            for (int num : nums) 
            {
                // Add current number to the cumulative sum.
                cumulativeSum += num;
                // If the cumulative sum exceeds maxSum, we need a new part.
                if (cumulativeSum > maxSum) 
                {
                    cumulativeSum = num; // start a new part
                    ++parts;
                }
            }
            // If the number of parts required is less than or equal to k, return true.
            return parts <= k;
        };

        // Binary search to find the minimum largest sum with which we can split the array into at most k parts.
        while (minMax < sum) 
        {
            int mid = (minMax + sum) / 2;
            // If we can split the array into at most k parts with max sum 'mid', search in the left half.
            if (canSplit(mid)) 
                sum = mid;
            // Otherwise, search in the right half.
            else 
                minMax = mid + 1;
        }

        // 'minMax' is now the minimum largest sum to split the array into at most k parts.
        return minMax;
    }
};