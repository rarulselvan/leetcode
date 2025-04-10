class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        string cleanStr;

        for(char x: s)
        {
            if(isalnum(x))
                cleanStr.push_back(tolower(x));
        }
        string cleanStrReversed=cleanStr;
        reverse(cleanStrReversed.begin(), cleanStrReversed.end());
        //cout <<s<<endl;
        //cout <<cleanStr<<endl;
        //cout <<cleanStrReversed<<endl;

        if(cleanStr==cleanStrReversed)
            return true;
        else
            return false;
    }
};
