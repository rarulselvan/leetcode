int missingNumber(int* nums, int numsSize)
{
//Approach 1:
    //get the biggest number
    //get the total n*(n+1)/2
    //get the array_sum
    //result=total-array_sum
//Approach 2:
printf("%d",numsSize);
    int res=numsSize;
    for(int i=0; i<numsSize; i++)
    {
        //xor of two element is zero. xor or three element is also zero
        //so xor the res(n), 0-n-1, nums, result is the missing number
        res=res^ i^nums[i];
    }
    return res;
}