class Solution 
{
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
                break;
            }
            if (x < target) 
                ++i;
             else 
                --j;
        }
        return {i+1, j+1};    }
};