class Solution
{
public:
    int maxNumberOfBalloons(std::string text) 
    {
        std::unordered_map<char, int> freq;

        // Count character frequencies in text
        for (char c : text)
            freq[c]++;

        // "balloon" has specific character frequency requirements
        return min({ 
            freq['b'], 
            freq['a'], 
            freq['l'] / 2,  // 'l' appears twice in "balloon"
            freq['o'] / 2,  // 'o' appears twice in "balloon"
            freq['n'] 
        });
    }
};