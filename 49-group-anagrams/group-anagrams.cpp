class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map <string, vector<string>>myMap;

        for(string x: strs)
        {
            string s=x;
            sort(s.begin(), s.end());
            myMap[s].push_back(x); //sorted string is the key into the hash map
        }

        vector<vector<string>> result;
        for (auto& group : myMap)
            result.push_back(group.second);
        return result;
    }
};

/*
unordered_map<string, vector<string>> anagramGroups;

        //sorted string -keep it as key
        //unsorted string - keep it as value

        // Iterate through each word
        for (string s : strs) 
        {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end()); // Sort the string
            
            anagramGroups[sortedStr].push_back(s); // Store the original word in the map
        }

        // Collect the grouped anagrams
        vector<vector<string>> result;
        for (auto& group : anagramGroups) 
            result.push_back(group.second);

        return result;
    }
    */