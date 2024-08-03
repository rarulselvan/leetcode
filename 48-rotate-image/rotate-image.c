void
swap (int **matrix, int i, int j)
{
  int temp = matrix[i][j];
  matrix[i][j] = matrix[j][i];
  matrix[j][i] = temp;
}
void
swaprow (int **matrix, int i, int j,int k)
{
  int temp = matrix[i][j];
  //cout<<temp<<"  "<<endl;
  matrix[i][j] = matrix[i][k];
  matrix[i][k] = temp;
}
void
rotate (int **matrix, int matrixSize, int *matrixColSize)
{
  int row = matrixSize;
  int col = *matrixColSize;
  int temp = 0;

  for (int i = 0; i < row; i++)
	for (int j = i; j < col; j++)
	  swap (matrix, i, j);

  //reverse the rows (for clock wise rotation)
  temp = row;
  row = col;
  int j=0;
  int k=0;
  for (int i = 0; i < row; i++)
	for (j = 0, k=row - 1; j < k ; j++,k-- )
    {
        swaprow(matrix, i, j, k);
    }
}