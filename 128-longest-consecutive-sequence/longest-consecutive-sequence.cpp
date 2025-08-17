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
    /*
     int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;

        // store unique numbers in sorted order
        set<int> st(nums.begin(), nums.end());

        int maxStreak = 1;
        int currentStreak = 1;

        auto prev = st.begin();
        for (auto it = next(st.begin()); it != st.end(); ++it)
        {
            if (*it == *prev + 1) {
                // consecutive → extend streak
                currentStreak++;
            } else {
                // not consecutive → reset streak
                currentStreak = 1;
            }
            maxStreak = max(maxStreak, currentStreak);
            prev = it;
        }
        return maxStreak;
    }*/
};