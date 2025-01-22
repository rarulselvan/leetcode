class Solution 
{
public:
    int longestOnes(vector<int> &arr, int k)
    {
        int res = 0;

        // Start and end pointer of the window 
        int start = 0, end = 0; 
        // Counter to keep track of zeros in current window
        int countk = 0;
        
        while (end < arr.size())
        {
            if (arr[end] == 0)
                countk++;
            
            // Shrink the window from left(move the start pointer to right) if number of zeroes are greater than k
            while (countk > k) 
            {
                if (arr[start] == 0)
                    countk--;        
                start++;
            }
            
            res = max(res, (end - start + 1));// the array start from zero hence add 1 here
            
            end++; //extend the end pointer by one of every iteration
        }
        return res;
    }
};