class Solution 
{
public:
    int ladderLength(string start, string target, vector<string>& wordList)
    {
        //Insert all the words into set
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // Target word not in dictionary
        if (wordSet.find(target) == wordSet.end()) 
            return 0;  

        queue<pair<string, int>> q;
        q.push({start, 1});  // (current word, steps)

        while (!q.empty()) 
        {
            auto [word, steps] = q.front();
            q.pop();

            if (word == target) 
                return steps;// Answer is retuned from here...
            
            // Try changing each character in the word
            for (int i = 0; i < word.length(); i++) 
            {
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) 
                {
                    if (ch == originalChar) 
                        continue;  // Skip same character

                    word[i] = ch;
                    if (wordSet.find(word) != wordSet.end()) 
                    {
                        q.push({word, steps + 1});
                        wordSet.erase(word);  // Mark word as visited
                    }
                }
                word[i] = originalChar;  // Restore original word
            }
        }
        return 0;  // No transformation sequence found
    }
};