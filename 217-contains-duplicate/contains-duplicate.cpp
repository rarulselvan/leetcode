class Solution {
public:
    bool containsDuplicate(vector<int>& arr) 
    {
        int n = arr.size();
    
        // Create an unordered_set to store the unique elements
        unordered_set<int> st;

        // Iterate through each element 
        for (int i = 0; i < n; i++) {
        
            // If the element is already present, return true 
            // Else insert the element into the set
            if (st.find(arr[i]) != st.end())
                return true;
            else 
                st.insert(arr[i]);
        }

        // If no duplicates are found, return false
        return false;
    }
};