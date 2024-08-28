void sortColors(int* nums, int numsSize) 
{
    int red=0;
    int white=0;
    int blue=0;
    for(int i=0;i<numsSize; i++)
    {
        if(nums[i]==0)
            red++;
        else if(nums[i]==1)
            white++;
        else
            blue++;
    }
    int index=0;

    while(red)
    {
        nums[index]=0; 
        index++;
        red--;
    }
    while(white)
    {
        nums[index]=1; 
        index++;
        white--;
    }
    while(blue)
    {
        nums[index]=2; 
        index++;
        blue--;
    }
}