class Solution 
{
public:
    int string_size;
    vector<string> possible_palindromes;
    unordered_map<char, int> charCount;

    vector<string> generatePalindromes(string s) 
    {
        string_size = s.size();

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
        depthFirstSearch(middle_element); //will have a charactor or 
        return possible_palindromes;
    }

    // Helper function to perform depth-first search to generate palindromes.
    void depthFirstSearch(string current_string) 
    {
        if (current_string.size() == string_size) 
        {
            possible_palindromes.push_back(current_string);
            return;
        }

        for (auto& [character, frequency] : charCount) 
        {
            if (frequency > 1) 
            {
                frequency -= 2;// charCount[character] -= 2; //By doing so the charactors (two) will not be visible in the recursion
                depthFirstSearch(character + current_string + character);                // Add the character on both sides of 'current_string' and recurse.
                frequency += 2;// charCount[character] += 2;                // Restore the charactors after the recursive call.
            }
        }
    }
};