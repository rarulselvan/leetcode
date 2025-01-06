class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) 
    {
        int cnt[51]{};
        //unordered_set<int, int>cnt;
        int ans = 0;
        for (int x : nums) 
        {
            ++cnt[x];
            if(cnt[x] == 2)
            {
                ans ^= x;
            }
        }
        return ans;
    }
};