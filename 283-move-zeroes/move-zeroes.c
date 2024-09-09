void moveZeroes(int* nums, int numsSize) 
{
    int left = 0;//non zero element pointer
    int right=0; //when ever there is an non zero move it...to left

    for (right = 0; right < numsSize; right++)
    {
        if (nums[right] != 0)
        {
            int temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;
            left++;
        }
    }
}