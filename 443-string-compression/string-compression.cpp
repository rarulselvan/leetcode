class Solution
{
public:
    int compress(vector<char>& chars) 
    {
        int writeIndex = 0; // Initializing write index to track the position to write the next character.
        int size = chars.size(); // Store the size of the input vector.
      
        int readStart=0;
        int readEnd=0;
        while(readStart<size)
        {
            readEnd=readStart+1;
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
            readStart = readEnd;//start with next char
        }    
        // Return the new length of the vector after compression.
        return writeIndex;
    }
};