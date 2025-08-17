class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.size()==0)
            return 0;
        
        //add all the elements into set to remove the duplicates
        set<int> st(nums.begin(), nums.end());
        int maxStreak = 0;
        for(int x:st)
            cout <<x <<" ";
        cout <<endl;
        for(auto num: st)
        {
            //If the previous number not exists...this is the first number in the streak hence check it out
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