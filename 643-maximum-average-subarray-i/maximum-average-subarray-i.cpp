class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int left=0;
        int res=0;

        //get first k elements in sum
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        res=sum;
        for(int i=k; i<nums.size(); i++)
        {
            sum = sum+nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return  static_cast<double>(res) / k;
    }
};