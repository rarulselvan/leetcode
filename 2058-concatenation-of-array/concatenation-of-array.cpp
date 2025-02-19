
class Solution 
{
public:
    vector<int> getConcatenation(vector<int>& nums)
    {
        vector<int>ans;
        for(auto x: nums)
            ans.push_back(x);
        for(auto x: nums)
            ans.push_back(x);
        //for (auto x : reverse(nums))         
        //ans.push_back(x);
        //for (auto it = nums.rbegin(); it != nums.rend(); ++it)
          //  ans.push_back(*it);
        return ans;
    }
};