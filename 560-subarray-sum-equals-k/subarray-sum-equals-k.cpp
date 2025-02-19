class Solution 
{
public:
 int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> sumCount = {{0, 1}}; // Initialize with sum 0 having one occurrence
    int cumulativeSum = 0, count = 0;

    for (int num : nums) {
        cumulativeSum += num;
        count += sumCount[cumulativeSum - k]; // Add count of subarrays that sum to k
        sumCount[cumulativeSum]++; // Update frequency of cumulativeSum
    }
    return count;
}
};
