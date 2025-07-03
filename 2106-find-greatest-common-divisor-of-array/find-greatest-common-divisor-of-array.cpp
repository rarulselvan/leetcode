class Solution 
{
public:
    int findGCD(vector<int>& nums) 
    {
        int minNum =INT_MAX;
        int maxNum =INT_MIN;
        
        for(auto x: nums)
            minNum=min(x, minNum);

        for(auto x: nums)
            maxNum=max(x, maxNum);

        return gcd(minNum, maxNum);
    }
};