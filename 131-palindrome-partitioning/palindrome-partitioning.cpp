class Solution 
{
public:
    vector<vector<string>> partition(string s) 
    {
        int n = s.size();
        vector<vector<int>> isPalindrome(n, vector<int>(n, true));
        
        // Precompute palindrome substrings
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
            }
        }

        unordered_map<int, vector<vector<string>>> dp;

        function<vector<vector<string>>(int)> dfs = [&](int i) -> vector<vector<string>>
        {
            if (dp.count(i)) return dp[i];  // Return memoized result
            if (i == n) return {{}};

            vector<vector<string>> result;
            for (int j = i; j < n; ++j) {
                if (isPalindrome[i][j]) {
                    string substring = s.substr(i, j - i + 1);
                    for (auto& rest : dfs(j + 1)) {
                        result.push_back({substring});
                        result.back().insert(result.back().end(), rest.begin(), rest.end());
                    }
                }
            }
            return dp[i] = result;  // Memoize result
        };

        return dfs(0);
    }
};