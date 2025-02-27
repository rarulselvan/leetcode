class Solution
{
    unordered_map<int, bool> dp;  // Memoization map
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // Convert to set for O(1) lookup
        dp.clear(); // Reset memoization for fresh calls
        return dfs(s, wordSet, 0);
    }

private:
    bool dfs(const string& s, const unordered_set<string>& wordSet, int index) 
    {
        if (index == s.length()) return true; // Successfully segmented the entire string
        if (dp.find(index) != dp.end()) return dp[index]; // Memoization check

        for (int len = 1; index + len <= s.length(); ++len) {
            string sub = s.substr(index, len);
            if (wordSet.count(sub) && dfs(s, wordSet, index + len)) {
                return dp[index] = true; // Store result in dp and return
            }
        }

        return dp[index] = false; // Mark this index as not breakable
    }
};