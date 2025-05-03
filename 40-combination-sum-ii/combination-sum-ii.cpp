class Solution 
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {

        vector<vector<int>>ans;
        vector<int>subAns;
        sort(candidates.begin(), candidates.end());
        function<void(int, int)>dfs;
        dfs=[&](int start, int sum)
        {
            if(sum<0)
                return;
            if(sum==0)
            {
                ans.push_back(subAns);
                return;
            }

            for(int j=start; j<candidates.size(); j++)
            {
                 if (j > start && candidates[j] == candidates[j - 1])
                    continue;
                subAns.push_back(candidates[j]);
                dfs(j+1,sum-candidates[j]);//same number chosen unlimited number of times.. so j is passed as it is
                subAns.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};