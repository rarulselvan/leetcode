class Solution 
{
public:
    bool searchNext(vector<vector<char>> &board, string word, int row, int col, int index, int m, int n) 
    {
        // if index reaches at the end that means we have found the word
        if (index == word.length())
            return true;

        // Checking the boundaries 
        if (row < 0 || col < 0 || row == m || col == n )
            return false;
        
        //if the character at which we are placed is not the required character
        if((board[row][col] != word[index]) || (board[row][col] == '#'))
            return false;

        // this is to prevent reusing(avoid loop) of the same character
        char c = board[row][col];
        board[row][col] = '#';
        
        bool top=false;
        bool right=false;
        bool bottom=false;
        bool left=false;

        // top direction
        top = searchNext(board, word, row - 1, col, index + 1, m, n);
        if(!top)
            right = searchNext(board, word, row, col + 1, index + 1, m, n);
        if(!right)
            bottom = searchNext(board, word, row + 1, col, index + 1, m, n);
        if(!bottom)
            left = searchNext(board, word, row, col - 1, index + 1, m, n);

        board[row][col] = c; // restore the charactor

        return top || right || bottom || left;
    }
    bool exist(vector<vector<char>> board, string word) 
    {
        int m = board.size();
        int n = board[0].size();

        int index = 0;

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {

                if (board[i][j] == word[index]) //try to match the first charactor in the matrix
                {
                    if (searchNext(board, word, i, j, index, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};