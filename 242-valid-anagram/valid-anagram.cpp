/*class Solution 
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() !=t.size())
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)
            return true;
        else
            return false;
    }
};
*/
class Solution 
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map <char, int>Map1;
        unordered_map <char, int>Map2;
        if(s.size() !=t.size())
            return false;
        for(auto x: s)
            Map1[x]++;
        for(auto x: t)
            Map2[x]++;
            
        if(Map1==Map2)
            return true;
        else
            return false;
    }
};