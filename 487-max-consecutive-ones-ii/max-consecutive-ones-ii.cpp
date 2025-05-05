class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int left=0;
        int right=0;
        int count=0;
        unordered_map<int, int> Map;

        for(right=0; right<nums.size(); right++)
        {
            Map[nums[right]]++;

            while(Map[0]>1)
            {
                Map[nums[left]]--;
                left++;
            }

            count=max(count, right-left+1);
        }
        return count;
    }
};