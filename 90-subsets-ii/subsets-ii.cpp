class Solution 
{
private:
        vector<int>subRes;
        vector<vector<int>>res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        function<void(int)>dfs;
        dfs=[&](int i)
        {
            res.push_back(subRes);
            if(i==nums.size())
                return;
            for(int j=i; j<nums.size(); j++)
            {
                if(j!=i && nums[j] == nums[j-1])
                    continue;
                subRes.push_back(nums[j]);
                dfs(j+1);
                subRes.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};