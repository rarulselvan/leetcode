class Solution
{
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> freqMap;

        // Count frequency of each character
        for (char c : s)
            freqMap[c]++;
        
        // Store in a vector as {frequency, character}
        vector<pair<int, char>> myPair;
        for (auto x : freqMap)
            myPair.push_back({x.second, x.first});
        
        // Sort in descending order based on frequency
        sort(myPair.rbegin(), myPair.rend());

        // Construct the result string
        string ans;
        for (auto x : myPair)
        {
            for(int i=0; i<x.first; i++)
                ans.push_back(x.second); // Append character 'x.second' 'x.first' times
        }
        
        return ans;
    }
};