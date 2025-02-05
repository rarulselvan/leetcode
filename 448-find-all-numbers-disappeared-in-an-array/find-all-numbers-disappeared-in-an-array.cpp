class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int i = 0;

//        sort(nums.begin(), nums.end());
        
        //cyclic sort the array
        while (i < nums.size()) 
        {
            int j = nums[i] - 1;

            if (nums[i] != nums[j])
                swap(nums[i], nums[j]);
            else 
                i++;
        }
        for(auto x :nums)
            cout <<x<< " ";
        
        vector<int> missingNumbers;

        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                missingNumbers.push_back(i + 1);
            }
        }
        return missingNumbers;
    }
};