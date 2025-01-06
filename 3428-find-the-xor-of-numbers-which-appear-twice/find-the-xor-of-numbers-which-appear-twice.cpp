class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) 
    {
        unordered_map<int, int>cnt;
        int ans = 0;
        for (int x : nums) 
        {
            cnt[x]++;
            if(cnt[x] == 2)
            {
                ans ^= x;
            }
        }
        return ans;
    }
};