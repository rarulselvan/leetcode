class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        vector<int> ans;
        int prev=0;
        for(auto x : nums)
        {
            ans.push_back(prev+x);
            prev=prev+x;
        }
        return ans;
    }
};