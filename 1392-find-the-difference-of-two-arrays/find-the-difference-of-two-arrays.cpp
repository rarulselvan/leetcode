
class Solution 
{
 public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> numset1{nums1.begin(), nums1.end()};
        unordered_set<int> numset2{nums2.begin(), nums2.end()};
        vector<vector<int>> ans(2);

        for (const int num : numset1)
        {
            if (!numset2.contains(num))//not having then add
                ans[0].push_back(num);
        }

        for (const int num : numset2)
        {
            if (!numset1.contains(num))
                ans[1].push_back(num);//not having then add
        }
        
        return ans;
    }
};