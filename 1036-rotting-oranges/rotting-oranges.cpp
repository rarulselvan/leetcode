/*
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
*/
class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int fresh = 0, time = 0;

        int rows = grid.size(), cols = grid[0].size();

        // Step 1: Count fresh oranges & enqueue all rotten oranges
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) fresh++;
                else if (grid[r][c] == 2) rotten.push({r, c});
            }
        }

        if (fresh == 0) return 0;  // No fresh oranges -> return 0 immediately
        if (rotten.empty()) return -1;  // No rotten oranges to spread infection

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Step 2: BFS to spread rot
        while (!rotten.empty()) {
            int length = rotten.size();
            bool anyRotten = false;

            for (int i = 0; i < length; i++) {
                auto [r, c] = rotten.front();
                rotten.pop();

                for (const auto& dir : directions) {
                    int row = r + dir.first, col = c + dir.second;
                    if (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        rotten.push({row, col});
                        fresh--;
                        anyRotten = true;
                    }
                }
            }

            if (anyRotten) time++;  // Increase time only if at least one orange rotted
        }

        return fresh == 0 ? time : -1;
    }
};