class Solution
{
public:
    // The compress function takes a vector of characters and compresses it by replacing
    // sequences of repeating characters with the character followed by the count of repeats.
    // It modifies the vector in-place and returns the new length of the vector after compression.
    int compress(vector<char>& chars) 
    {
        int writeIndex = 0; // Initializing write index to track the position to write the next character.
        int size = chars.size(); // Store the size of the input vector.
      
        // Loop over characters in the vector starting from the first character.
        for (int readStart = 0, readEnd = readStart + 1; readStart < size;) 
        {
            // Expand the readEnd pointer to include all consecutive identical characters.
            while (readEnd < size && chars[readEnd] == chars[readStart]) 
                readEnd++;
            
                // Write the character to the vector.
                chars[writeIndex++] = chars[readStart];
            
                // If the run of characters is more than one, write the count after the character.
                int runLength = readEnd - readStart;
                if (runLength > 1) 
                {
                    // Convert runLength to string and write each digit individually.
                    for (char countChar : to_string(runLength)) 
                        chars[writeIndex++] = countChar;    
                }
            // Move the readStart to the next character group.
            readStart = readEnd;
        }
      
        // Return the new length of the vector after compression.
        return writeIndex;
    }
};