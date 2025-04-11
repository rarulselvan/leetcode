class Solution 
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        //0111 ---->1110
        int result=0;
        int count =32;
        while(count>0)
        {
            result=result<<1;

            if(n&1)
                result=result|1;
            n=n>>1;
            count--;
        }
        return result;
    }
};