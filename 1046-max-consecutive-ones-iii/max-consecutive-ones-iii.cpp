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
            
            // Shrink the window from left if number of 
            // zeroes are greater than k
            while (countk > k) 
            {
                if (arr[start] == 0)
                    countk--;        
                start++;
            }
            
            res = max(res, (end - start + 1));
            
            // Increment end pointer to expand the window
            end++; 
        }
        
        return res; 
    }
};