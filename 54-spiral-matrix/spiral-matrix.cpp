class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int row=matrix.size();
        int col=matrix[0].size();
        int totalElements=row*col;    

        int cs=0;
        int ce=col;
        int rs=0;
        int re=row;
        int count=0;
        vector<int>result;

        while (count < totalElements)
        {
            for (int j = cs; count < totalElements && j < ce; j++)
            {
                result.push_back(matrix[rs][j]);
                count++;
            }
            rs = rs+1;

            for (int i = rs; count < totalElements && i < re; i++) 
            {
                result.push_back(matrix[i][ce - 1]);
                count++;
            }
            ce = ce-1;

            for (int j = ce - 1; count < totalElements && j >= cs; j--)
            {
                result.push_back(matrix[re - 1][j]);
                count++;
            }
            re = re- 1;

            for (int i = re - 1; count < totalElements && i >= rs; i--)
            {
                result.push_back(matrix[i][cs]);
                count++;
            }
            cs += 1;
        }
        return result;
    }
};