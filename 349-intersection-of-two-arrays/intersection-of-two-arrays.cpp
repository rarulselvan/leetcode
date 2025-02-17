/*
class Solution {
public:

vector<int> intersection(vector<int>nums1, vector<int>nums2)
{
    bool s[1001];
    memset(s, false, sizeof(s));
    
    for (int x : nums1) 
    {
        s[x] = true;
    }
    vector<int> ans;
    for (int x : nums2)
    {
        if (s[x])
        {
            ans.push_back(x);
            s[x] = false;
        }
    }
    return ans;
    }
};
*/
class Solution 
{
public:

    vector<int> intersection(vector<int>nums1, vector<int>nums2)
    {
        unordered_map<int, int> Map;
        for (int x : nums1) 
        {
            Map[x] = true;
        }
        vector<int> ans;
        for (int x : nums2)
        {
            if (Map[x])
            {
                ans.push_back(x);
                Map[x] = false;
            }
        }
        return ans;
        }
};