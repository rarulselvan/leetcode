class Solution 
{
public:
    int string_size;
    vector<string> possible_palindromes;
    unordered_map<char, int> charCount;

    vector<string> generatePalindromes(string s) 
    {
        string_size = s.size();

        // Counting the frequency of each character in the input string.
        for (char c : s) 
            charCount[c]++;

        // 'middle_element' can only have one character in odd count for palindromes.
        string middle_element = "";
        for (auto& [character, frequency] : charCount) {
            // If the frequency is odd and 'middle_element' is already set,
            // it means we cannot form a palindrome.
            if (frequency %2 ) 
            {
                if (!middle_element.empty()) {
                    return possible_palindromes; // Return as no palindromic permutations possible.
                }
                // Assign the middle element.
               middle_element = character;
            }
        }

        // Starting DFS with the potential middle element.
        depthFirstSearch(middle_element);
        return possible_palindromes;
    }

    // Helper function to perform depth-first search to generate palindromes.
    void depthFirstSearch(string current_string) 
    {
        // If the current string's size matches the input size, we found a palindrome.
        if (current_string.size() == string_size) 
        {
            possible_palindromes.push_back(current_string);
            return;
        }

        // Construct new palindromes by adding characters around the 'current_string'.
        for (auto& [character, frequency] : charCount) 
        {
            // We should have at least 2 characters to place around 'current_string'.
            if (frequency > 1) {
                frequency -= 2;
                // Add the character on both sides of 'current_string' and recurse.
                depthFirstSearch(character + current_string + character);
                // Restore the count after the recursive call.
                frequency += 2;
            }
        }
    }
};