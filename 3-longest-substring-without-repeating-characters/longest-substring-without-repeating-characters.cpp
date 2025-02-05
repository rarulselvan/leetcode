class Solution 
{
public:
/*    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> myMap;
        int res = 0;
        int j = 0;
        // This is a sliding window problem
        // j is left most pointer
        // i is right most pointer
        for (int i = 0; i < s.size(); i++)
        {
            // if the charactor is available in the map ....
            if (myMap.count(s[i]) > 0)
            {
                //move the j to the available charactor position...
                cout << myMap[s[i]] << "  ";
                j = max(j, myMap[s[i]] + 1);
            }
            //
            res = max(res, i - j + 1);
            myMap[s[i]] = i;// store the locations
        }
        return res;
    }
    */
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<int, int> Map;
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
                i=max(i, Map[s[j]]+1); // max is required to handle "abba" case...
                cout <<i<<" ";
            }
            res= max(res,j-i+1);//Nunmber of unique charactors ...

            Map[s[j]]=j; //store the charactor and it's position in map
        }
        return res;
    }
};