class Solution 
{
public:
    int minSteps(string s, string t)
    {
        unordered_map<char, int> Map;

        for (auto i : s) 
            Map[i]++;// Increasing the count if the no. is present
        
        int count=0;
        for (auto x : t)
        {
            // Checking the charactors are present or not 
            if (Map[x] > 0) 
                Map[x]--;  // If present then decrease the no. in map by 1
            
            else
                count++;    // If not present increase count by 1
        }
        return count;
    }
};