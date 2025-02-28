class Solution 
{
public:
    string decodeString(string s) 
    {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;
        for(auto c : s)
        {
            if (isdigit(c)) 
                k = k * 10 + (c - '0'); // Build multi-digit number ... 12[a] ...12 has to be constructed
            else if (c == '[')
            {
                countStack.push(k); // Store repeat count
                stringStack.push(currentString); // Store previous substring
                k = 0;
                currentString = "";
            }
            else if (c == ']')
            {
                int repeat = countStack.top(); countStack.pop();
                string decodedString = stringStack.top(); stringStack.pop();

                // Repeat current string and append to the previous one
                while (repeat--) 
                    decodedString += currentString;

                currentString = decodedString;
            } 
            else 
                currentString += c; // Append regular character that is 'a', 'bc' in 3[a]2[bc]
        }
        return currentString;
    }
};