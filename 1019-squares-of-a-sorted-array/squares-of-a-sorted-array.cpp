class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++)
            nums[i] = nums[i] * nums[i];

        // Sort an array using "sort STL function "
        sort(nums.begin(), nums.end());
        return nums;
    }
};