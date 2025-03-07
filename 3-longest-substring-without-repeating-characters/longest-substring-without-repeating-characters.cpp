/*
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
*/
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        // This unordered set is used to store the characters that are currently in the
        // longest substring without repeating characters.
        unordered_set<char> slidingSet;

        // The starting index of the substring.
        int start = 0;
        int maxLength = 0;

        for (int end = 0; end < s.size(); ++end) 
        {
            // If the character at the current ending index of the substring already exists
            // in the character set, continue to remove characters from the start of the
            // substring until the character is no longer in the set.
            while (slidingSet.count(s[end])) 
            {
                slidingSet.erase(s[start]);
                start += 1;
            }

            // Insert the current character into the set.
            slidingSet.insert(s[end]);

            // Calculate the length of the current substring and update maxLength
            // if this length is the largest we've found so far.
            maxLength = max(maxLength, end - start + 1);
        }
        // Return the length of the longest substring found.
        return maxLength;
    }
};