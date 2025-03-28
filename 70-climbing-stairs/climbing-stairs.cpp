class Solution 
{
private:
    vector<int>dp;
public:
    int climbStairs(int n) 
    {
        dp.resize(n+1, -1);
        return climbStairsDP(n);
    }
    int climbStairsDP(int n) 
    {
        if(n ==0)
            return 1;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        if(dp[n] !=-1)
            return dp[n];

        return dp[n] = climbStairsDP(n-1)+climbStairsDP(n-2); 
    }
};