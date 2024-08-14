int missingNumber(int* nums, int numsSize)
{
//Approach 1:
    //get the biggest number
    //get the total n*(n+1)/2
    //get the array_sum
    //result=total-array_sum
//Approach 2:
    int res=numsSize;
    for(int i=0; i<numsSize; i++)
        res=res^ i^nums[i];
    return res;
}