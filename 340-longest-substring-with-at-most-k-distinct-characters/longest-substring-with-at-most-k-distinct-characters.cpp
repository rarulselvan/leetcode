class Solution 
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        unordered_map<char, int>charCount;
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int maxDistinctCount = 0;

        for (right = 0; right < s.size(); right++)
        {
            charCount[s[right]]++;

            while (charCount.size() > k)//if distinct char size is more than 'k' shrink the window
            {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0)
                    charCount.erase(s[left]);//Erase the entry(You would incorrectly think there are more than k distinct characters in the window, 
                                                //even when one (or more) have a count of 0 and no longer matter)
                left++;
            }
            cout<<"go to the next char"<<endl;

            //calculate the max length on cases no need to shrink the window
            int windowsSize=right-left+1;
            maxLen = max(maxLen, windowsSize);
        }
        return maxLen;
    }
};