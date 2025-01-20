class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int len=nums.size()-1;
        return binarysearch(nums, 0, len, target);   
    }
    int binarysearch(vector<int>& nums,int low, int high, int target)
    {
        if(low<=high)
        {
            int mid=low+(high-low)/2;
            if(target==nums[mid])
                return  mid;
            else if(target>nums[mid])
            {
                 cout <<low<<"  "<<high<<endl;
                return binarysearch(nums, mid+1,high, target);
            }
            else
            {
                cout <<low<<"  "<<high<<endl;
                return binarysearch(nums, low, mid-1, target);
            }
        }
        return -1;
    }
};