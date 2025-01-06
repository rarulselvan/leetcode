class Solution {
public:
    vector<int> majorityElement(vector<int>& arr)
    {
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> res;

        // find frequency of each number
        for (int ele : arr)
            freq[ele]++;

        // Iterate over each key-value pair in the hash map
        for (auto it : freq)
        {
            int ele = it.first;
            int cnt = it.second;

            // Add the element to the result, if its frequency
            // if greater than floor(n/3)
            if (cnt > n / 3)
                res.push_back(ele);
        }
        return res;
    }
};