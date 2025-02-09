class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& insert)
    {
        intervals.push_back(insert);
        return merge(intervals);
    }
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
                vector<int> &prev=res.back();
                vector<int> &curr=x;
                if(prev[1]>=curr[0])
                    prev[1]= max(prev[1], curr[1]);
                else
                    res.push_back(curr); 
            }
        }
        return res;
    }
};