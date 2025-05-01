/*class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> slidingSet;

        // The starting index of the substring.
        int start = 0;
        int maxLength = 0;

        for (int end = 0; end < s.size(); end++) 
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

            int currLength=slidingSet.size();
            maxLength = max(maxLength, currLength);
        }
        // Return the length of the longest substring found.
        return maxLength;
    }
};
*/
class Solution 
{
public:
    int lengthOfLongestSubstring(string& s) 
    {
        int res = 0;
        unordered_map<char, int>Map;
        int left = 0; 
        int right = 0;

        for(right=0; right < s.length(); right++)
        {
            while (Map[s[right]])  //If the charactor is already available move the left pointer
            {
                Map[s[left]]--;
                left++;
            }
            //Now add the charactor into map
            Map[s[right]]++;

            // The length of the current window (right - left + 1) is calculated and answer is updated accordingly.
            res = max(res, (right - left + 1));
        }
        return res;
    }
};