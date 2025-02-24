/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
            
        //Remove the duplicates...
        unordered_set<int> st(nums.begin(), nums.end());
        int maxStreak = 0;

        for (auto num : st) 
        {
            // Only start a sequence if 'num' is the first element of the sequence
            if (!st.count(num - 1)) 
            {
                int currentNum = num;
                int currentStreak = 1;

                // Continue adding consecutive numbers to the sequence
                while (st.count(currentNum + 1)) 
                {
                    currentNum++;
                    currentStreak++;
                }

                // Update the longest streak found
                maxStreak = max(maxStreak, currentStreak);
            }
        }
        return maxStreak;
    }
};
*/
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.size()==0)
            return 0;
        
        //add all the elements into set to remove the duplicates
        unordered_set<int> st(nums.begin(), nums.end());
        int maxStreak = 0;


        for(auto num: st)
        {
            if(!st.count(num-1))
            {
                int currentNum = num;
                int currentStreak = 1;
                while (st.count(currentNum + 1)) 
                {
                    currentNum++;
                    currentStreak++;
                }
                maxStreak=max(maxStreak,currentStreak);
            }
        }
        return maxStreak;
    }
};























