class Solution 
{
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int, int> cnt;
        int ans = n + 1;
        int s=0;
        int i=0;

        for (int j = 0; j < n; j++) 
        {
            s = s|nums[j];
            for (int h = 0; h < 32; ++h) 
            {
                if ((nums[j] >> h & 1) == 1)
                    ++cnt[h];
            }
            for (; s >= k && i <= j; ++i) 
            {
                ans = min(ans, j - i + 1);
                for (int h = 0; h < 32; ++h) 
                {
                    if ((nums[i] >> h & 1) == 1) 
                    {
                        if (--cnt[h] == 0)
                            s ^= 1 << h;
                    }
                }
            }
        }
        return ans > n ? -1 : ans;
    }
};