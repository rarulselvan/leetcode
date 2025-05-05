class Solution 
{
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        // Initialize the checks for rows, columns, and blocks
        bool rowCheck[9][9] = {false};
        bool colCheck[9][9] = {false};
        bool blockCheck[3][3][9] = {false};
        bool isSolved = false; // Flag to indicate if the solution is found
      
        // Stores empty positions (represented as '.') in the board
        vector<pair<int, int>> emptyPositions;
      
        // Build the initial state for empty positions and the values present
        for (int i = 0; i < 9; ++i) 
        {
            for (int j = 0; j < 9; ++j) 
            {
                if (board[i][j] == '.') 
                {
                    // Keep track of empty positions for backtracking
                    emptyPositions.push_back({i, j});
                } 
                else 
                {
                    // Calculate the value present in the cell
                    int value = board[i][j] - '1';
                    // Mark the value present in the corresponding row, column, and block
                    rowCheck[i][value] = colCheck[j][value] = blockCheck[i / 3][j / 3][value] = true;
                }
            }
        }
      
        // Define the DFS function for backtracking
        function<void(int)> dfs = [&](int index) 
        {
            // Base case: if all empty positions are filled
            if (index == emptyPositions.size()) 
            {
                isSolved = true; // Solution found
                return;
            }
          
            // Get the position to fill
            int row = emptyPositions[index].first;
            int col = emptyPositions[index].second;
          
            // Try all possible values in the current position
            for (int value = 0; value < 9; value++) 
            {
                // Check if the value is not already present in the row, column, or block
                if (!rowCheck[row][value] && !colCheck[col][value] && !blockCheck[row / 3][col / 3][value]) 
                {
                    // Place the value and update the state
                    rowCheck[row][value] = colCheck[col][value] = blockCheck[row / 3][col / 3][value] = true;
                    board[row][col] = value + '1';
                  
                    // Continue with the next position
                    dfs(index + 1);
                  
                    // If solution is found, no need to explore further
                    if (isSolved)
                        return;
                  
                    // Undo the decision and backtrack
                    rowCheck[row][value] = colCheck[col][value] = blockCheck[row / 3][col / 3][value] = false;
                }
            }
        };
      
        // Start the DFS from the first empty position
        dfs(0);
    }
};
