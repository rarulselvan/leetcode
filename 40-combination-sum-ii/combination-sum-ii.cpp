class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;    
        vector<int>subAns;

        sort(candidates.begin(), candidates.end());
        
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
                if(j!=i && candidates[j] == candidates[j-1])
                    continue;
                subAns.push_back(candidates[j]);
                dfs(j+1,sum-candidates[j]);
                subAns.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
