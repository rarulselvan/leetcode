bool checkPal(char *s, int low, int high)
{
    while (low < high)
    {
        if (s[low] == s[high])
        {  
            low++;
            high--;
        }
        else
            return false;
    }
    return true;
}

char* longestPalindrome(char* s) 
{
    int n = strlen(s);

    // All substrings of length 1 are palindromes
    int maxLen = 1, start = 0;

    // Nested loop to mark start and end index
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {  
            // Check if the current substring is a palindrome
            if (checkPal(s, i, j))
            if( (j - i + 1) > maxLen) // greater than the previous palindrome?
            {
                //if yes mark teh start and length (end position)
                start = i;
                maxLen = j - i + 1;
            }
        }
    }
    char *result=(char*) malloc(sizeof(char)*(maxLen+1));
    strncpy(result, s + start, maxLen);
    result[maxLen] = NULL;   
    return result;
}