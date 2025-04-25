class Solution 
{
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }

private:
    int atMostKDistinct(const vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq;
        int left = 0, right = 0, count = 0;
        
        //while (right < nums.size()) 
        for(int right=0; right<nums.size();)
        {
            if (freq[nums[right]] == 0) 
                k--;
            
            freq[nums[right]]++;
            right++;

            while (k < 0) 
            {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    k++;
                
                left++;
            }

            count += right - left;
        }
        return count;
    }
};