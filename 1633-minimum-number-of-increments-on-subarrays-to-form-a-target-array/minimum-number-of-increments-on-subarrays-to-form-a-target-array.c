int minNumberOperations(int* target, int targetSize)
{

    int operations = target[0];
    printf("/n %d", operations);
    for (int i = 1; i < targetSize; i++) 
    {
        if (target[i] > target[i - 1])
        {
            printf("incement...%d",target[i] - target[i - 1]);
            operations += target[i] - target[i - 1];
        }
    }
    return operations;
}