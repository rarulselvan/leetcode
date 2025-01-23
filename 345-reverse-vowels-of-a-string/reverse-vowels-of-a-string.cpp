class Solution 
{
public:
    bool isVowel(char c)
{
    return (c=='a' || c=='A' || c=='e' ||
            c=='E' || c=='i' || c=='I' ||
            c=='o' || c=='O' || c=='u' ||
            c=='U');
}
 string reverseVowels(string str)
{
    // Start two indexes from two corners
    // and move toward each other
    int i = 0;
    int j = str.length()-1;
    while (i < j)
    {
        if (!isVowel(str[i]))
        {
            i++;
            continue;
        }
        if (!isVowel(str[j]))
        {
            j--;
            continue;
        }
 
        // swapping
        swap(str[i], str[j]);
 
        i++;
        j--;
    }
 
    return str;
}
};