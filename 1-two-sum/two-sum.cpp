/*class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
       // vector<int> *ans = new vector<int >;
       for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    cout<<"found it"<<endl;
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++) 
        {
            if (nums[j] == target- nums[i])
            {
                int *ans = (int *) malloc(sizeof(int)*2);
                ans[0] = i;
                ans[1] = j;
                *returnSize=2;
                return ans;
            }
        }
    }
    return NULL;
} */

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector <int> res;

        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); i++)
            pairs.push_back({nums[i], i});
    

        sort(pairs.begin(), pairs.end());

        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            int sum=pairs[i].first + pairs[j].first;
            if(sum==target)
            {
                res.push_back(pairs[i].second);
                res.push_back(pairs[j].second);
                break;
            }
            else if(sum<target)
                i++;
            else
                j--;
        }
        return res;
    }
};