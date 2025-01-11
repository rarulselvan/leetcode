class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int res = 0, n = s.size();
        
        // Try replacing other characters to form 
        // a string of each character 'A' to 'Z'
        for (char c = 'A'; c <= 'Z'; c++)
        {
            int l = 0, r = 0, cnt = 0;
            
            // Sliding window from l to r
            while (r < n)
            {
                if (s[r] == c)
                    r++;
                else if (cnt < k)
                    r++, cnt++;
                else if (s[l] == c)
                    l++;
                else
                    l++, cnt--;
                
                // Update the maximum length of substring
                res = max(res, r - l);
            }
        }
        return res;
    }
};