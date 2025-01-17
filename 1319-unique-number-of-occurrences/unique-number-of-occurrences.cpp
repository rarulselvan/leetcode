class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
     {
        unordered_map<int, int> freq;
        set<int> freqSet;
 
        for(int i = 0; i < arr.size(); i++)
            freq[arr[i]]++;
 
        for(auto it : freq)
            freqSet.insert(it.second);
        cout << freq.size() <<" "<<freqSet.size()<<endl;
        return (freq.size()==freqSet.size());
    }
};