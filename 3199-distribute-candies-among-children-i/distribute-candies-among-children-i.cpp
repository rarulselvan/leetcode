class Solution 
{
public:
    int distributeCandies(int n, int limit) 
    {
        int count = 0;
        // Iterate over all possible values for x and y
        if(3*limit <n)
            return 0;
        for (int x = 0; x <= limit; ++x)
        {
            for (int y = 0; y <= limit; ++y) 
            {
                int z = n - x - y;
                if (0 <= z && z <= limit)
                    ++count;
            }
        }
        return count;
    }
};