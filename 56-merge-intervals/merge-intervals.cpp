class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) 
    {
        //sort based on the first element (start) in the pair
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        
        for(auto x: arr)
        {
            if(res.size()==0)
                res.push_back(x);
            else
            {
                vector<int>& last = res.back();
                vector<int>& curr = x;
                if(curr[0] <= last[1])
                    last[1]= max(last[1], curr[1]);
                else
                    res.push_back(curr); 
            }
        }
        return res;
    }
};