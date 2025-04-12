class Solution {
public:
    int hammingWeight(int n) 
    {
        int count =0;
        while(n)
        {
            n&1? count++:count;
            n=n>>1;
        }
        return count;
    }
};