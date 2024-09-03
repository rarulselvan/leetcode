class Solution {
public:
    bool containsDuplicate(vector<int>& arr) 
    {
        int n = arr.size();
    
        set<int> arrSet;

        // Iterate all elements one by one
        for (int i = 0; i < n; i++)
        {
        
            // If the element is already present, return true 
            // Else insert the element into the set
            if (arrSet.find(arr[i]) != arrSet.end())
                return true;
            else 
                arrSet.insert(arr[i]);
        }
        // If no duplicates are found, return false
        return false;
    }
};
