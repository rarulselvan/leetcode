class Solution 
{
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int, int> remainderFreq;
        remainderFreq[0] = 1; // Initial prefix sum is 0
        int sum = 0, count = 0;

        for (int num : nums) 
        {
            sum += num;
            int mod = ((sum % k) + k) % k; // Ensure non-negative mod

            if (remainderFreq.find(mod) != remainderFreq.end())
                count += remainderFreq[mod];

            remainderFreq[mod]++;
        }

        return count;
    }
};
