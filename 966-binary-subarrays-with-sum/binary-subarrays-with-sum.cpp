class Solution 
{
public:

    int atmost(vector<int>& arr, int k)
    {
        if (k < 0)
            return 0;
            
        int n = arr.size();
        int res = 0, sum = 0, j = 0;
        
        for (int i=0; i<n; i++) 
        {    
            while (j < n && sum+arr[j] <= k) 
            {
                sum += arr[j];
                j++;
            }
            
            // Number of sub-arrays starting from
            // index i that have sum atmost k will 
            // be (j-i).
            res += (j - i);
            
            // Remove the i'th index from window.
            sum -= arr[i];
        }
        return res;
    }

    // Function to find count of subarrays
    // with sum equal to k
    int numSubarraysWithSum(vector<int>& arr, int k) {

        // Call atmost(arr, k) and atmost
        // (arr, k-1) to get the count of
        // subarrays with sum at most k
        // and sum at most k-1 respectively,
        // then subtract them to get the count
        // of subarrays with sum exactly
        // equal to k
        return atmost(arr, k) - atmost(arr, k - 1);
    }
};