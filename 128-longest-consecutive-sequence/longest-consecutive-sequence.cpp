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
            if(st.count(num-1)==0)
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























