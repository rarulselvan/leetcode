class Solution 
{
private:
    vector<int>dp;
public:
   
    int fib(int n)
    {
        dp.assign(n+1, -1);
        return fibcal(n);
    }
    int fibcal(int n)
    {
        
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        if(dp[n] !=-1)
        {
           // cout <<"already computed..."<<endl;
            return dp[n];
        }
        return dp[n]=fibcal(n-1)+fibcal(n-2);
    }
};