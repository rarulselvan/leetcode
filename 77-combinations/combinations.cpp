class Solution 
{

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> t;

        function<void(int)> dfs = [&](int i) 
        {
            //Base case
            if (t.size() == k) 
            {
                ans.emplace_back(t);
                return;
            }
            //Base case
            if (i > n)
                return;
            
            t.push_back(i);
            dfs(i + 1);
            t.pop_back();
            dfs(i + 1);
        };
        //this will terminate when the arg reaches n
        dfs(1);
        return ans;
    }
};