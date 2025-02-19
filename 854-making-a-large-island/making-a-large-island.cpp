class Solution 
{
public:
    int n;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int dfs(vector<vector<int>>& grid, int i, int j, int islandID)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
            return 0;
        
        //convert 1 into ID... 2 or 3 or 4 etc
        grid[i][j] = islandID; // Mark visited with unique island ID
        int size = 1;
        for (auto& dir : directions) 
            size += dfs(grid, i + dir[0], j + dir[1], islandID);
        return size;
    }

    int largestIsland(vector<vector<int>>& grid)
    {
        n = grid.size();
        unordered_map<int, int> islandSize;  // ( Island ID: Island Size)
        int islandID = 2;
        int maxIsland = 0;

        // Step 1: Identify and label islands
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid[i][j] == 1) 
                {
                    int size = dfs(grid, i, j, islandID);
                    islandSize[islandID++] = size;
                    maxIsland = max(maxIsland, size);//compute this max island for step 2
                }
            }
        }

        // Step 2: Try flipping each 0 and merge islands
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (grid[i][j] == 0) 
                {
                    unordered_set<int> seenIslands;
                    int newSize = 1; // Include the flipped cell
                    
                    for (auto& dir : directions) 
                    {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && y >= 0 && x < n && y < n
                                    && grid[x][y] > 1) //Already marked island (ie , 2 or 3 or 4 etc)
                            seenIslands.insert(grid[x][y]);//store the island label
                    }
                    
                    for (int id : seenIslands) 
                        newSize += islandSize[id];
                    
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }
        return maxIsland;
    }
};