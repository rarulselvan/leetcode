bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) 
{
    int targetInRow=0;

    for(int i=0; i<matrixSize; i++)
    {
        if(target >= matrix[i][0])
            targetInRow=i;
    }
    for(int j=0; j<*matrixColSize; j++)
    {
        if(matrix[targetInRow][j]== target)
            return true;
    }
    //("%d", targetInRow);
    return false;
}