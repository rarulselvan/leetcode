class Solution 
{
public:
    // Helper function to perform backtracking with memoization
    vector<string> wordBreakHelper(string& s, unordered_set<string>& dictSet, 
                               unordered_map<int, vector<string>>& dp, 
                               int start) 
    {

        // If the result for this index is already computed, simply return it
        if (dp.count(start)) 
            return dp[start];

        vector<string> result;

        // If start reaches the end of the string, add an empty string to signify a valid sentence
        if (start == s.length())
        {
            result.push_back("");
            return result;
        }

        // Try every possible substring from the current index
        for (int end = start + 1; end <= s.length(); ++end)
        {
            string word = s.substr(start, end - start);

            // Check if the word exists in the dictionary
            if (dictSet.count(word)) 
            {
                // Recursively checkfor the remaining string
                vector<string> subSentences = wordBreakHelper(s, dictSet, dp, end);

                // Append the current word to each valid sub-sentence
                for (string& sub : subSentences) 
                {
                    if (sub.empty()) 
                        result.push_back(word);
                    else 
                        result.push_back(word + " " + sub);
                }
                for(auto x: result)
                    cout <<x<<" ";
                cout <<endl;
            }
        }

        // Memorize the result for the current index
        dp[start] = result;
        return result;
    }

    // Main function to generate all possible sentence breaks
    vector<string> wordBreak(string s, vector<string>& dict) 
    {
        // Convert dictionary vector to an unordered set
        unordered_set<string> dictSet(dict.begin(), dict.end());

        unordered_map<int, vector<string>> dp; 

        return wordBreakHelper(s, dictSet, dp, 0);
    }
};