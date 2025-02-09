class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> Map;
        for (int num : nums)
            Map[num]++;
        vector<pair<int, int>> arr;
        for(auto x: Map)
            arr.push_back({x.second, x.first});
        
        sort(arr.rbegin(), arr.rend());

        vector <int> res;
        for(int i=0; i<k; i++)
            res.push_back(arr[i].second);
        
        for(auto x : res)
            cout <<x <<" "; 
        return res;
    }
};