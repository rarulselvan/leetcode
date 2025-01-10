/*class Solution {
public:
    double myPow(double x, int n)
    {
        double ans=1;
        if(n>0)
        {
            for(int i=0; i<n; i++)
                ans=ans*x;
        }
        else
        {
            n=abs(n);
            for(int i=0; i<n; i++)
            {
                ans=ans/n;
                cout<<ans<<" ";
            }
        }
        return ans;
    }
};
*/


class Solution 
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n > 0) 
        {
            return pow(x, n);
        } 
        else
        {
            return pow(1.0 / x, abs((double)n));
        }
    }

    double pow(double x, long n)
    {
        double res = 1;
        double product = x;
        while (n > 0)
        {
            if (n % 2 == 1) 
            {
                res *= product;
            }
            product = product * product;
            n = n / 2;
        }
        return res;
    }
};