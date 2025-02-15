class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int i=0;
        int j=numbers.size()-1;
        vector<int>res;
        while(i<j)
        {
            int x = numbers[i] + numbers[j];
            if (x == target) 
            {
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            }
            if (x < target) 
                ++i;
             else 
                --j;
        }
        return res;
    }
};