class Solution 
{
public:
    int commonFactors(int a, int b) 
    {
        int commonFactorCount=0;
        int gcdVal=gcd(a,b);

        //Try all values starting from "1" to min(a,b) or "gcdval"
        for (int divisor = 1; divisor <= min(a, b); divisor++)
        {
            if (gcdVal % divisor == 0)
                commonFactorCount++;
        }
        return commonFactorCount;
    }
};