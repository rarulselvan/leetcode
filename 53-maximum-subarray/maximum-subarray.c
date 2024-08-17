int maxSubArray(int* nums, int numsSize)
{
    int globalMaxima=-10000;
    int localMaxima=0;

    for(int i=0; i<numsSize; i++)
    {
        localMaxima=localMaxima+nums[i];
        if(localMaxima > globalMaxima)
            globalMaxima=localMaxima;
        if(localMaxima<0)
            localMaxima=0; //reset the negative 
    }
    return globalMaxima;
}