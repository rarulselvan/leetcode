class Solution 
{
public:    
    int maxAbsoluteSum(vector<int>& nums) 
    {
        // Initialize the variables to keep track of the current max and min subarray sum
        int currentMaxSum = 0;
        int currentMinSum = 0;
      
        // Variable to store the final maximum absolute sum
        int maxAbsoluteSum = 0;  

    
        for (int& num : nums) 
        {
            // Update currentMaxSum: reset to zero if it becomes negative, then add the current element
            currentMaxSum = max(0, currentMaxSum) + num;

            // Update currentMinSum: reset to zero if it is positive, then add the current element
            currentMinSum = min(0, currentMinSum) + num;

            // Find the maximum between currentMaxSum and the absolute value of currentMinSum
            // Update maxAbsoluteSum if necessary
            maxAbsoluteSum = max({maxAbsoluteSum, currentMaxSum, abs(currentMinSum)});
        }
      
        // Return the final maximum absolute sum
        return maxAbsoluteSum;
    }
};