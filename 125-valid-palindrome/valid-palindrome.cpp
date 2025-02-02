class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        string cleanStr;
        for(auto ch : s)
        {
            if(isalnum(ch))
                cleanStr.push_back(tolower(ch));
            else
                ;//discard . , : ; etc in the origianl string
        }
        string cleanStrReverse=cleanStr;
        reverse(cleanStrReverse.begin(), cleanStrReverse.end());

        return cleanStrReverse==cleanStr;
    }
};