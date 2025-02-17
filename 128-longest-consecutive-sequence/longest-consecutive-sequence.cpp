class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
    
        unordered_set<int> s(nums.begin(), nums.end()); // Store all unique elements in a set
        int longestStreak = 0;

        for (int num : s) 
        {
            // Only start a sequence if 'num' is the first element of the sequence
            if (!s.count(num - 1)) 
            {
                int currentNum = num;
                int currentStreak = 1;

                // Continue adding consecutive numbers to the sequence
                while (s.count(currentNum + 1)) 
                {
                    currentNum++;
                    currentStreak++;
                }

                // Update the longest streak found
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};