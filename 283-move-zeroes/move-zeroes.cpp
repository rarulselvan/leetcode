class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int j = 0; // Pointer for placing non-zero elements
        
        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] != 0) 
            {
                swap(nums[i], nums[j]); // Swap non-zero with zero
                j++;
            }
        }
    }
};