class Solution {
public:
     vector<vector<int>> threeSum(vector<int>& nums) 
     {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) 
        {
            if (i >0 )// skip the consecutive elements if they are same
            {
                if(nums[i] == nums[i - 1])
                   continue;
            }
            cout<<" i="<<i<<endl;
            int left = i + 1, right = n - 1;
            while (left < right) 
            {
                int x = nums[i] + nums[left] + nums[right];
                if (x < 0) 
                    left++;
                else if (x > 0) 
                    right--;
                else
                {
                    //found the triplet...push into vector
                    ans.push_back({nums[i], nums[left], nums[right]});
                    //..left++..right -- to continue search the left over array elements
                    left++;
                    right --;
                }
            }
        }
        sort(ans.begin(), ans.end());
        // Remove consecutive duplicate elements
        auto it = unique(ans.begin(), ans.end());
        // Erase the duplicate vectors
        ans.erase(it, ans.end());
        return ans;
    }
};

