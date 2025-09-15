class Solution 
{
private:
    vector<int>dp;
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        dp.resize(nums.size()+1,-1);
        int res=0;

        for(int i=0; i<nums.size(); i++)
            lisEndAtI(nums, i);
        
        for(int i=0; i<nums.size();i++)//get the max in the array
            res=max(res, dp[i]);        
        return res;
    }
    int lisEndAtI(vector<int> &nums, int i)
    {
        if (dp[i] != -1) 
            return dp[i];
        
        int mx = 1; //start with one because every increasing sequence there are two numbers

        //for (int prev = 0; prev <i; prev++)
        for (int prev = i-1; prev >=0; prev--)
        {
            if (nums[prev] < nums[i])
                mx = max(mx, 1+lisEndAtI(nums, prev));
        }
        cout <<i <<" "<<mx<<endl;
        dp[i]=mx;
        return mx;
    }
};

/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // dp[i] = LIS ending at i

        int res = 1;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                if (nums[j] < nums[i]) 
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
*/