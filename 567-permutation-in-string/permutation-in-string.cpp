class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        unordered_map<char, int> s1Count;
        unordered_map<char, int> s2Count;

        int left = 0;
        for (left = 0; left < s1.size(); left++)
            s1Count[s1[left]]++;
        
        for (left = 0; left < s1.size()-1; left++)
            s2Count[s2[left]]++;
            
        left=0;
        
        for (int right = s1.size() -1; right < s2.size(); right++)
        {
            s2Count[s2[right]]++;
            if (s1Count == s2Count) 
                return true;
            
            s2Count[s2[left]]--; // remove the leftmost character from the window
            if (s2Count[s2[left]] == 0)
                s2Count.erase(s2[left]);  // Clean up zero count
            left++;
        }

        return false;
    }
};