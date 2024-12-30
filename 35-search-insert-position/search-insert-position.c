int searchInsert(int* nums, int numsSize, int target)
 {
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i]==target)
            return i;
        if(nums[i]>target && i==0)
            return 0;
        if(nums[i]<target && i==numsSize-1)
            return i+1;
        if(nums[i]<target && nums[i+1]>target)
            return i+1;
    }
    return -1;
}