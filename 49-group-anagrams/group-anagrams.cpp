/*class Solution {
public:
        string getHash(string &s) 
        {
            string hash;
            vector<int> freq(26, 0);
            
            // Count frequency of each character
            for(char ch: s)
                freq[ch - 'a'] += 1;
            
            // Append the frequency to construct the hash
            for(int i = 0; i < 26; i++) {
                hash.append(to_string(freq[i]));
                hash.append("$");
            }
            
            return hash;
        }

        vector<vector<string>> groupAnagrams(vector<string> &arr) 
        {
            vector<vector<string>> res;
            unordered_map<string, int> mp;
            for (int i = 0; i < arr.size(); i++) {
                string key = getHash(arr[i]);
            
                // If key is not present in the hash map, add
                // an empty group (vector) in the result and
                // store the index of the group in hash map
                if (mp.find(key) == mp.end()) {
                    mp[key] = res.size();
                    res.push_back({});
                }
            
                // Insert the string in its correct group
                res[mp[key]].push_back(arr[i]);
        }
        return res;
    }
};*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        // Iterate through each word
        for (string s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end()); // Sort the string
            
            anagramGroups[sortedStr].push_back(s); // Store the original word in the map
        }

        // Collect the grouped anagrams
        vector<vector<string>> result;
        for (auto& group : anagramGroups) {
            result.push_back(group.second);
        }

        return result;
    }
};