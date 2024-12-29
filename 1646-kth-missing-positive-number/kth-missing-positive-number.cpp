class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    // Insert all array elements into a set
    unordered_set<int> s(arr.begin(), arr.end());

    int count = 0, curr = 0;
    while (count < k) 
    {
        curr++;
        // Increment missing count if current
        // element is missing
        if (s.find(curr) == s.end())
            count++;     
    }
    return curr;
    }
};
