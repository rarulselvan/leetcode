
class NumArray 
{
private:
    vector <int> prefixSum;
public:

    NumArray(vector<int>& nums) 
    {
        int size = nums.size();
        prefixSum.resize(size + 1); // Resizing with an extra element to handle the zero prefix sum.
        prefixSum[0] = 0; // Initialize the zero-th index with 0 for the prefix sum.

        // Calculate the prefix sum by adding the current element to the accumulated sum.
        for (int i = 0; i < size; ++i) 
            prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    
    int sumRange(int left, int right)
    {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */