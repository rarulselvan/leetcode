
/*class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n);
        vector<int> dg(n << 1);
        vector<int> udg(n << 1);
        vector<vector<string>> ans;
        vector<string> t(n, string(n, '.'));
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                ans.push_back(t);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (col[j] + dg[i + j] + udg[n - i + j] == 0) {
                    t[i][j] = 'Q';
                    col[j] = dg[i + j] = udg[n - i + j] = 1;
                    dfs(i + 1);
                    col[j] = dg[i + j] = udg[n - i + j] = 0;
                    t[i][j] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
};
*/
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