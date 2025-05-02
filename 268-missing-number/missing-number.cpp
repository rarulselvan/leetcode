class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int sum=0;
        int len=nums.size();
    
        for(auto x: nums)
            sum=sum+x;
        return (len*(len+1)/2 -sum);
    }
};