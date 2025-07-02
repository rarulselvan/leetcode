/*
class Solution 
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> Map;

        for(int i=0; i<nums.size(); i++)
        {
            int x1 = nums[i];
            int x2 = target - x1;

            // Check if the 2nd element  exists in the set
            if (Map.find(x2) != Map.end())
                return {i, Map[x2]};
            else
                Map[x1]=i;
        }
        return {};
    }
};
*/
class Solution 
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> Map;

        for(int i=0; i<nums.size(); i++)
        {
            int x1 = nums[i];
            int x2 = target - x1;

            // Check if the 2nd element  exists in the set
            if (Map.contains(x2))// != Map.end())
                return {i, Map[x2]};
            else
                Map[x1]=i;
        }
        return {};
    }
};