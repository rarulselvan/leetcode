class Solution 
{
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> countMap;
        for(string word:words)
            countMap[word]++;

        //  creates a vector named wordFrePair and initializes it with the 
        //  elements of the Unordered Map Freq
        vector <pair<string, int>> wordFrePair(countMap.begin(), countMap.end());

        // sort the vector based on the custom comparator function 
        sort(wordFrePair.rbegin(), wordFrePair.rend(), myComparator);

        // declare resultant vector which contains expected output
        vector <string> result;
        // declare a varible idx to access temp elements
        int idx = 0;

        while (idx < k)
        {
            // it variable will have the string and freq 
            // it.first contains string
            // it.second contains freq of that sring
            auto it = wordFrePair[idx];
            // inserting our string into our resultant vector
            result.push_back(it.first);
            // increamenting the idx variable
            // so that we can access the next element
            idx++;
        }
        return result;
        
    }
    static bool myComparator (pair <string, int> &a, pair <string, int> &b)
    {
        if (a.second == b.second)
            return a.first > b.first;

        return a.second < b.second;
    }
};