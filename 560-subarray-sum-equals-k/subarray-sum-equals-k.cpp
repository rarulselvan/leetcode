class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k)
     {
        unordered_map<int, int> prefixSumFrequency;
        prefixSumFrequency[0] = 1; // Base case: there's one way to have a sum of 0 (no elements).
      
        int answer = 0;  
        int cumulativeSum = 0; 
      
        for (int num : nums) 
        {
            cumulativeSum += num; // Update the cumulative sum.
            // If cumulativeSum - k exists in prefixSumFrequency, then a subarray ending at current
            // index has a sum of k. We add the count of those occurrences to answer.
            answer += prefixSumFrequency[cumulativeSum - k];
            // We then increment the count of cumulativeSum in our frequency map.
            prefixSumFrequency[cumulativeSum]++;
        }
      
        // Return the total count of subarrays that sum up to k.
        return answer;
    }
};

