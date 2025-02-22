class Solution
{
public:
    int getLargestOutlier(vector<int>& nums) 
    {
        int s = 0;
        unordered_map<int, int> Map;
        for (int x : nums) 
        {
            s += x;
            Map[x]++;
        }
        int ans = INT_MIN;
        for (auto [x, v] : Map) 
        {
            int t = s - x;
            if (t % 2 || !Map.contains(t / 2))
             {
                continue;
            }
            if (x != t / 2 || v > 1) {
                ans = max(ans, x);
            }
        }
        return ans;
    }
};