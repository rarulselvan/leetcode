/*
class Solution {
public:
    int subarraySum(vector<int>& arr, int sum)
    {
        // unordered_set to store prefix sums.
        unordered_set<int> prefixSums;
        int res = 0;
        int currSum = 0;

        for (int i = 0; i < arr.size(); i++) 
        {
            // Add current element to sum so far.
            currSum += arr[i];

            // If currSum is equal to desired sum, then a new
            // subarray is found. So increase count of subarrays.
            if (currSum == sum)
                res++;

            // If currSum exceeds the desired sum, check if 
            // the difference  exists in the prefixSums set.
           // if(currSum>sum)
            {
                if (prefixSums.find(currSum - sum) != prefixSums.end())
                    res++;
            }

            // Add currSum to the set of prefix sums.
            prefixSums.insert(currSum);
        }
        return res;
    }
};
*/
class Solution {
public:
    int subarraySum(vector<int>& arr, int k)
     {
        int n = arr.size();
        int prefix[n]; // make a prefix array to store prefix sum
        
        // create the prefix array
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + arr[i];
        
        
        unordered_map<int,int> mp; // declare an unordered map    
        int ans = 0; // to store the number of our subarrays having sum as 'k'
    
        for(int i = 0; i < n; i++) // traverse from the prefix array
        {
            if(prefix[i] == k) // if it already becomes equal to k, then increment ans
                ans++;
            
            // now, as we discussed find whether (prefix[i] - k) present in map or not
            if(mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k]; // if yes, then add it our answer
            }
            
            mp[prefix[i]]++; // put prefix sum into our map
        }
        
        return ans; // and at last, return our answer
    }
};

