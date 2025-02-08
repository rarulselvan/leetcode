/*class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int> stk;
        unordered_map<int, int> d;
        ranges::reverse(nums2);
        for (int x : nums2) 
        {
            while (!stk.empty() && stk.top() < x) 
                stk.pop();
            
            if (!stk.empty()) 
                d[x] = stk.top();
            
            stk.push(x);
        }
        vector<int> ans;
        for (int x : nums1) 
        {
            ans.push_back(d.contains(x) ? d[x] : -1);
        }
        return ans;
    }
};*/
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int> stk;
        unordered_map<int, int> d;
       // ranges::reverse(nums2);// Either reverse the array or process it from the end using for loop
        for(int i=nums2.size()-1; i>=0; i--)
        {
            int x= nums2[i];
            while (!stk.empty() && stk.top() < x) 
                stk.pop();
            
            if (!stk.empty()) 
                d[x] = stk.top();
            
            stk.push(x);
        }
        vector<int> ans;
        for (int x : nums1) 
        {
            ans.push_back(d.contains(x) ? d[x] : -1);
        }
        return ans;
    }
};