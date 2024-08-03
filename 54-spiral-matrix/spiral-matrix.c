/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int* result = (int*)malloc(matrixSize * (*matrixColSize) * sizeof(int));
    int rs = 0;
    int re = matrixSize;
    int cs = 0;
    int ce = *matrixColSize;
    int totalElements = re * ce;
    int count = 0; 
    int i=0;

    while (count < totalElements)
    {
        for (i = cs; count < totalElements && i < ce; i++)
            result[count++] = matrix[rs][i];
        rs += 1;

        for (i = rs; count < totalElements && i < re; i++) 
            result[count++] = matrix[i][ce - 1];
        ce -= 1;

        for (i = ce - 1; count < totalElements && i >= cs; i--)
            result[count++] = matrix[re - 1][i];
        
        re -= 1;

        for (i = re - 1; count < totalElements && i >= rs; i--)
            result[count++] = matrix[i][cs];
        
        cs += 1;
    }

    *returnSize = count;
    return result;
}

