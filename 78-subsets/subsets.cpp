class Solution
{
public:
    void findSubsets(vector<int>& v, int idx,
                 vector<int>& subset,
                 set<vector<int> >& result)
    {
        // If the current subset is not empty
        // insert it into the result
        if (!subset.empty())
            result.insert(subset);

        // Iterate over every element in the array
        for (int j = idx; j < v.size(); j++) {

            // Pick the element and move ahead
            subset.push_back(v[j]);
            findSubsets(v, j + 1, subset, result);

            // Backtrack to drop the element
            subset.pop_back();
        }
    }

// Function to return all unique subsets

    vector<vector<int> > subsets(vector<int>& v) 
    {
        // To store the resulting subsets
        set<vector<int> > result;
        vector<int> subset;

        // Helper function call
        findSubsets(v, 0, subset, result);

        vector<vector<int> > res;
        res.push_back({});//insert the empty set
        for (auto x : result)
            res.push_back(x);

        return res;
    }
};