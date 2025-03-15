class Solution {
public:
    int maxDistToClosest(std::vector<int>& seats) 
    {
        int n = seats.size();
        int t = 0;
        int res = 0;
        bool firstOccupied =false;

        for(int i = 0; i < n; i++)
        {
            if(seats[i] == 1)
            {
                if(firstOccupied == false)
                {
                    res = i;
                    firstOccupied=true;
                }
                else
                    res = max(res, (i - t) / 2);
    
                t = i;
            }
        }
        res = max(res, n - 1 - t);
        return res;
    }
};
