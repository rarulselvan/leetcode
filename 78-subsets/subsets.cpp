class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>subAns;

        function<void(int)>dfs;
        dfs=[&](int start)
        {
            if (!subAns.empty())
                ans.push_back(subAns);
            
            for(int j=start; j<nums.size(); j++)
            {
                subAns.push_back(nums[j]);
                dfs(j+1);
                subAns.pop_back();
            }
        };
        ans.push_back(subAns);//empty set
        dfs(0);
        return ans;
    }
};