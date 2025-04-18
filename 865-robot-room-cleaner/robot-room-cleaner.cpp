/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution 
{
public:
    void cleanRoom(Robot& robot) 
    {
        int directions[5] = {-1, 0, 1, 0, -1};
        set<pair<int, int>> visited;
      
        // Depth-first search algorithm to traverse and clean the room recursively
        function<void(int,int, int)>dfs;
        dfs = [&](int i, int j, int dir)
        {
            //Clean and mark it
            robot.clean();
            visited.insert({i, j});

            // Attempt up/down, left, right directions
            for (int k = 0; k < 4; k++) 
            {
                // Calculate the new direction after turning
                int newDir = (dir + k) % 4;
                // Calculate the coordinates of the adjacent cell
                int x = i + directions[newDir], y = j + directions[newDir + 1];

                // If the adjacent cell has not been visited and we can move there,
                // we move, clean the cell, and backtrack after
                if (visited.count({x, y}) == 0 && robot.move()) 
                {
                    dfs(x, y, newDir);

                    // Backtrack to the previous cell (requires two turns and move)
                    robot.turnLeft();
                    robot.turnLeft();
                    robot.move();
                    robot.turnLeft();
                    robot.turnLeft();
                }
                // Turn the robot to face the next direction
                robot.turnLeft();
            }
        };

        // Start the cleaning process from (0, 0) facing up (direction index 0)
        dfs(0, 0, 0);
    }
};
