class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int>Map;

        for(char c: magazine)
            Map[c]++;

        for( char c : ransomNote)
        {
            if(Map[c])
                Map[c]--;
            else
                return false;
        }
        return true;
    }
};