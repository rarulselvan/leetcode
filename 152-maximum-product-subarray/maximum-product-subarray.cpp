class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxProduct = nums[0], minProduct = nums[0], result = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) swap(maxProduct, minProduct); // Swap when negative

            maxProduct = max(nums[i], maxProduct * nums[i]);
            minProduct = min(nums[i], minProduct * nums[i]);

            result = max(result, maxProduct); // Update global max
        }

        return result;
    }
};