class Solution
{
public:
    int minBitFlips(int a, int b)
    {
        // Return count of set bits in
        // a XOR b
        a=a^b;
        int count=0;
        while(a)
        {
            if(a%2)
                count++;
            a=a>>1;
        }

        return count;
    }

};