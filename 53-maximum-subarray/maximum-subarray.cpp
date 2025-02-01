class Solution 
{
private:
    int localMaxima=0;
    int globalMaxima=INT_MIN;
public:
    int maxSubArray(vector<int>& nums) 
    {
         for(int num : nums)
        {
            localMaxima=localMaxima+num;
            if(localMaxima > globalMaxima)
                globalMaxima=localMaxima;
            if(localMaxima<0)
                localMaxima=0; //reset
        }
        return globalMaxima;
    }
};