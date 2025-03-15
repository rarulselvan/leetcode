class Solution 
{
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<int> colposition(n);
        vector<int> dgposition(n << 1);
        vector<int> udgposition(n << 1);
        vector<vector<string>> ans;
        vector<string> t(n, string(n, '.'));

        function<void(int)> dfs = [&](int row)
        {
            if (row == n) 
            {
                //got the solution save it and return
                ans.push_back(t);
                return;
            }
            for (int col = 0; col < n; col++) 
            {
                if (colposition[col] ==0 && dgposition[row + col] ==0 && udgposition[n - row + col] == 0) 
                {
                    t[row][col] = 'Q';
                    colposition[col] = dgposition[row + col] = udgposition[n - row + col] = 1;
                    dfs(row + 1);//call itself
                    colposition[col] = dgposition[row + col] = udgposition[n - row + col] = 0;
                    t[row][col] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
};
/*
class Solution {
  public:
    bool isSafe1(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) 
    {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) 
        board[i] = s;

      solve(0, board, ans, n);
      return ans;
    }
};
*/