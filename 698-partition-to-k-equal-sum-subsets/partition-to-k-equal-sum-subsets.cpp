class Solution 
{
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0); //'0'- is the initials value
        if (totalSum % k != 0) 
            return false;//not possible

        int targetSum = totalSum / k;
        sort(nums.rbegin(), nums.rend());
        
        vector<int> subsetSums(k, 0);

        function<bool(int)> dfs = [&](int index)
        {
            //Reached the end of array ? break here 
            if (index == nums.size())
                return true;

            // the for loop is for the 'k' baskets or sets
            for (int j = 0; j < k; ++j) 
            {
                if (subsetSums[j] + nums[index] > targetSum) 
                    continue;// this basket is full attempt the next basket

                subsetSums[j] += nums[index];
                if (dfs(index + 1))
                    return true;

                subsetSums[j] -= nums[index];

                if (subsetSums[j] == 0) 
                    break; // Unable to place and element hence ..helpless return
            }
            return false;
        };
        return dfs(0);
    }
};