class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) 
    {
        if(intervals.size()==0)
            return true;
       // Sort the meetings by their start times
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size() - 1; i++)  //-1 is required since we are comparing two elements
        {
            // Compare the current meeting's end time with the  next meeting's start time to check for overlap
            if(intervals[i][1] > intervals[i + 1][0])
                return false;
        }
        return true;
    }
};