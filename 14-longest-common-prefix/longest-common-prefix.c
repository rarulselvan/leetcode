
char* longestCommonPrefix(char** strs, int strsSize) 
{
    if (strsSize == 0) return "";
    int i, j;
    for (i = 0; i < strlen(strs[0]); i++) 
    {
        for (j = 1; j < strsSize; j++) 
        {
            if (i >= strlen(strs[j]) || strs[0][i] != strs[j][i])
            {
                char* result = (char*)malloc((i + 1) * sizeof(char));
                strncpy(result, strs[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }
    return strs[0];
}
