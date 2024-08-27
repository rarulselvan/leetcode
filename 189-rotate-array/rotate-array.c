void rotate(int* nums, int numsSize, int k) 
{
    k = k % numsSize; //get the reminder
    int* temp = (int*)malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) 
    {
        temp[i] = nums[(i - k + numsSize) % numsSize];
    }
    
    for (int i = 0; i < numsSize; i++) 
    {
        nums[i] = temp[i];
    }
    
    free(temp);
}