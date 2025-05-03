class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int target)
    {
        vector<vector<int>>ans;
        vector<int>subAns;
        function<void(int, int)>dfs;
    
        dfs=[&](int start, int sum)
        {
            if(sum<0)
                return;
            if(subAns.size()>k)
                return;
            if(sum==0 && subAns.size()==k)
            {
                ans.push_back(subAns);
                return;
            }

            for(int j=start; j<=9; j++)
            {

                subAns.push_back(j);
                dfs(j+1,sum-j);//same number chosen unlimited number of times.. so j is passed as it is
                subAns.pop_back();
            }
        };
        dfs(1, target);
        return ans;
    }
};