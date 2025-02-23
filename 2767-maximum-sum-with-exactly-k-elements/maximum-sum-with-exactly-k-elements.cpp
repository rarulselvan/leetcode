class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) 
    {
        int max=0;
        int ans=0;

        for(int i=0; i<nums.size(); i++)
        {
            if(max<nums[i])
                max=nums[i];
        }
        cout <<max<<endl;
        for(int i=0; i<k; i++)
        {
            ans=ans+max;
            max++;
        }
        return ans;
    }
};