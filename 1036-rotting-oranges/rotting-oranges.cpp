class Solution {
public:
   int orangesRotting(vector<vector<int>>& grid) 
   {
        queue<pair<int, int>> rotton;
        int fresh = 0;
        int time = 0;

        for (int r = 0; r < grid.size(); r++) 
        {
            for (int c = 0; c < grid[0].size(); c++) 
            {
                if (grid[r][c] == 1)
                    fresh++;
                if (grid[r][c] == 2)
                    rotton.push({r, c});
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (fresh && !rotton.empty())
        {
            int length = rotton.size();
            for (int i = 0; i < length; i++) 
            {
                auto curr = rotton.front();
                rotton.pop();
                int r = curr.first;
                int c = curr.second;

                for (const auto& dir : directions) //try all four directions
                {
                    int row = r + dir.first;
                    int col = c + dir.second;
                    if (row >= 0 && row < grid.size() && 
                        col >= 0 && col < grid[0].size() &&
                        grid[row][col] == 1) // fresh orange 
                    {
                        grid[row][col] = 2; // convert to rotton orange
                        rotton.push({row, col}); // add the rotton into queue
                        fresh--; // fresh is down by one 
                    }
                }
            }
            //all the rotton oranges are processed... in this new rotton are added into queue
            time++; //one minute up
            //Now the all rotton(old+new) will be processed 
        }
        return fresh == 0 ? time : -1;
    }
};