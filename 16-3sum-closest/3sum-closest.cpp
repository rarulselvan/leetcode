class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        // three number can be anywhere in the array... need notbe consecutive .hence sort it
        sort(nums.begin(),nums.end());
        
        int res = 0XFFFF;

        for(int i=0; i<nums.size()-2; i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==target)
                    return sum;
                if (abs(target-sum) < abs(target-res))  //get the abs of sum and ans(previous sum) from target ... and get the minimim value
                    res = sum;
                if (sum < target)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};