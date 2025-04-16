class Solution 
{
public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        long long sum =0;
        long long maxSum=0;        
        unordered_map<int, int> mapCount; // frequency of elements

        if(nums.size()<k)
            return -1;

        for (int i = 0; i < k; i++) 
        {
            mapCount[nums[i]]++;
            sum += nums[i];
        }
        if(mapCount.size()==k)
            maxSum=sum; 
        else
            maxSum=0;

        for(int i=k; i<nums.size(); i++)
        {
            mapCount[nums[i]]++; //Incoming element
            sum = sum+nums[i]; //Incoming element
          
            mapCount[nums[i - k]]--;//outgoing element
            sum = sum - nums[i - k];//outgoing element

            // If the outgoing element count reached zero...remove it from the map
            if (mapCount[nums[i - k]] == 0) 
                mapCount.erase(nums[i - k]);
            
            // Update maxSum if current window contains k unique elements
            if (mapCount.size() == k)
                maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};