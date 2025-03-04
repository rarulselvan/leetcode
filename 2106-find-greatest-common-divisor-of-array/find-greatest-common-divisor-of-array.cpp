class Solution 
{
public:
    int findGCD(vector<int>& nums) 
    {
        int minNum =INT_MAX;
        int maxNum =INT_MIN;
        for(auto x: nums)
        {
            if(x<minNum)
                minNum=x;
        }
        for(auto x: nums)
        {
            if(x>maxNum)
                maxNum=x;
        }
        return gcd(minNum, maxNum);
    }
};