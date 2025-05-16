class Solution 
{
private:
    vector<vector<int>>res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {  
        function<void(int)>dfs;
        dfs=[&](int idx)
        {
            if (idx == nums.size())
            {
                res.push_back(nums);
                return;
            }

            for (int i = idx; i < nums.size(); ++i)
            {
                swap(nums[idx], nums[i]);
                dfs(idx + 1);
                swap(nums[idx], nums[i]);
            }
        };

        dfs(0);

        sort(res.begin(), res.end());
        auto last = unique(res.begin(), res.end());
        res.erase(last, res.end());

        return res;
    }
};