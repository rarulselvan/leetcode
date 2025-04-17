class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;    
        vector<int>subAns;

        function<void(int, int)>dfs;
        dfs=[&](int i, int sum)
        {
            if(sum==0)
            {
                ans.push_back(subAns);
                return;
            }
            if(sum<0)
                return;
            for(int j=i; j<candidates.size(); j++)
            {
                subAns.push_back(candidates[j]);
                dfs(j,sum-candidates[j]);
                subAns.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};

