class Solution
{
public:
    // Function to find k smallest pairs with minimal sum
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Lambda function to compare pairs based on the sum of elements they point to in nums1 and nums2
        auto comparePairs = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        // Get the sizes of the input arrays
        int size1 = nums1.size();
        int size2 = nums2.size();

        // Variable to store the final pairs
        vector<vector<int>> result;
      
        // Priority queue to keep pairs in ascending order based on their sum
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparePairs)> minHeap(comparePairs);
      
        // Initialize the priority queue with the first pair from each element in nums1
        for (int i = 0; i < min(k, size1); ++i) {
            minHeap.emplace(i, 0);
        }

        // Extract the k smallest pairs
        while (k-- > 0 && !minHeap.empty()) {
            auto [index1, index2] = minHeap.top();
            minHeap.pop();

            // Add the current smallest pair to the result
            result.push_back({nums1[index1], nums2[index2]});
          
            // If there's a next element in nums2, add the new pair to the priority queue
            if (index2 + 1 < size2) {
                minHeap.emplace(index1, index2 + 1);
            }
        }

        // Return all k smallest pairs found
        return result;
    }
};