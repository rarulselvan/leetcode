class Solution 
{
public:
    int getSum(int a, int b) 
    {
        //Full adder
        int sum=a;
        int carry=0;
        while(b!=0)
        {
            sum=a^b;
            carry=(a&b)<<1;
            a=sum;
            b=carry;
        }
        return sum;
    }
};