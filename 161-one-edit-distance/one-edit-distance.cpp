class Solution 
{
public:
    bool isOneEditDistance(string s, string t) 
    {
        int lenS = s.length(), lenT = t.length();

        // Guarantee that 's' is not shorter than 't'
        if (lenS < lenT) return isOneEditDistance(t, s);

        if ((lenS - lenT) > 1) return false;

        for (int i = 0; i < lenT; ++i) 
        {
            if (s[i] != t[i]) 
            {
                if (lenS == lenT)
                    return s.substr(i + 1) == t.substr(i + 1);
                return s.substr(i + 1) == t.substr(i);
            }
        }

        // If all previous characters matched, check for append operation
        return lenS == lenT + 1;
    }
};