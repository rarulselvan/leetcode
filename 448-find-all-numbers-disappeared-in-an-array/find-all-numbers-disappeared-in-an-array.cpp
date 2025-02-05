class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int i = 0;

//        sort(nums.begin(), nums.end());
        
        while (i < nums.size()) {
            int j = nums[i] - 1;

            if (nums[i] != nums[j]) {
                // swap
                std::swap(nums[i], nums[j]);
            } else {
                i++;
            }
        }
        
        std::vector<int> missingNumbers;

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                missingNumbers.push_back(i + 1);
            }
        }

        return missingNumbers;
    }
};