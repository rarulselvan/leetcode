
class Solution 
{
public:
    int totalNQueens(int n) 
    {
        vector<int> colposition(n);
        vector<int> topLeftDiagonal(n *2);//topLeftDiagonal
        vector<int> topRightDiagonal(n *2);//topRightDiagonal

        int  ans;

        function<void(int)> dfs;
        dfs = [&](int row)
        {
            if (row == n) 
            {
                //got the solution save it and return
                ans++;
                return;
            }
            for (int col = 0; col < n; col++)
            {
                if (colposition[col] ==0 && topLeftDiagonal[n + col-row] ==0 && topRightDiagonal[col+row] == 0) 
                {        
                    colposition[col] = topLeftDiagonal[n+col-row] = topRightDiagonal[col+row] = true;
                    dfs(row + 1);
                    colposition[col] = topLeftDiagonal[n+col-row] = topRightDiagonal[col+row] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};