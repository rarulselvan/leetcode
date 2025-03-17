class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
          unordered_map<char, char> mapS, mapT;

        if (s.size() != t.size()) 
            return false;

        for (int i = 0; i < s.length(); i++) 
        {
            char cS = s[i], cT = t[i];

            // Ensure both mappings are consistent
            if ((mapS.count(cS) && mapS[cS] != cT) || (mapT.count(cT) && mapT[cT] != cS))
                return false;

            // Establish the mapping
            mapS[cS] = cT;
            mapT[cT] = cS;
        }
        return true;
    }
};