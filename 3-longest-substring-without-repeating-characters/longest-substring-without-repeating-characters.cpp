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
        unordered_map<char, int>vis;
        int left = 0; 
        int right = 0;

        for(right=0; right < s.length(); right++)
        {
            // If character is repeated, move left pointer marking
            // visited characters as false until the repeating 
            // character is no longer part of the current window
            while (vis[s[right]] == true) 
            {
                vis[s[left]] = false;
                left++;
            }

            vis[s[right]] = true;

            // The length of the current window (right - left + 1)
            // is calculated and answer is updated accordingly.
            res = max(res, (right - left + 1));
        }
        return res;
    }
};