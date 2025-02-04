class Solution {
public:
    int maxDifference(string s)
    {
        unordered_map<char, int>myMap;

        for(char x: s)
        myMap[x]++;

        vector<int>frequencies;
        for(auto x:myMap)
            frequencies.push_back(x.second);

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        for (int x:frequencies)
        {
            if(x%2==0)
            {
                 if(minEven >x) minEven=x;
            }
            else
            {
                 if(maxOdd<x) maxOdd=x;
            }

        }
        return maxOdd-minEven;
    }
};