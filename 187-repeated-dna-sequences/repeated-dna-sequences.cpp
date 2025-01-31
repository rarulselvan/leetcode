class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        // Use an unordered_map for efficient lookup and insertion
        unordered_map<string, int> sequenceCount;
      
        // Calculate the number of possible starting indices for 10-letter sequences
        int possibleStarts = s.size() - 9;
      
        // Prepare a vector to store the resulting repeated sequences
        vector<string> repeats;
      
        // Loop through the string to examine all possible 10-letter sequences
        for (int i = 0; i < possibleStarts; ++i) {
            // Extract a 10-letter substring starting at index i
            string subsequence = s.substr(i, 10);
          
            // Increment the count for this particular sequence
            // If the count becomes 2, it implies this is the second time we've seen it,
            // so we add it to the list of repeats
            if (++sequenceCount[subsequence] == 2) {
                repeats.push_back(subsequence);
            }
        }
      
        // Return the list of repeated sequences
        return repeats;
    }
};