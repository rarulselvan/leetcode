class Solution 
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> Map;
        int i=0;
        int j=0;
        int res=0;
        
        // Sliding window ... j...is right's position.... i is in the left's position
        for(j=0; j<s.size(); j++)
        {
            // check the charactor is present in the map...
            if(Map.count(s[j])>0)
            {
                //now move the i forward till that charactor position ... slide the window
                i=max(i, Map[s[j]]+1); // max is required to handle "abba" case... if we do not do "max" i  will move backward
                //i=Map[s[j]]+1;
                cout <<i<<" ";
            }
            res= max(res,j-i+1);//Nunmber of unique charactors ...

            Map[s[j]]=j; //store the charactor and it's position in map...this will be overwritten
        }
        return res;
    }
};