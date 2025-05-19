class Solution {
public:
    // This function checks if there is a 132 pattern in the input vector "nums".
    // A 132 pattern is a subsequence of three integers where the first is smaller than the third and both are smaller than the second.
    bool find132pattern(vector<int>& nums) {
        // Initialize the variable to hold the value of the third element in the 132 pattern, initialized to the minimum integer value.
        int thirdValue = INT_MIN;
      
        // Use a stack to help find potential candidates for the second element in the 132 pattern.
        stack<int> candidates;
      
        // Iterate through the input array backwards.
        for (int i = nums.size() - 1; i >= 0; --i) {
            // Check if we have achieved the 132 pattern
            if (nums[i] < thirdValue) {
                // we found a valid 132 pattern
                return true;
            }
            // While we have candidates and the current number is greater than the candidate at the top of the stack
            while (!candidates.empty() && candidates.top() < nums[i]) {
                // The candidate could potentially be the third value in the pattern, so we update the thirdValue.
                thirdValue = candidates.top();
                candidates.pop(); // Remove the candidate as it has been used
            }
            // Push the current number onto the stack to be a candidate for the second position in the 132 pattern.
            candidates.push(nums[i]);
        }
      
        // If we reach this point, no 132 pattern has been found.
        return false;
    }
};