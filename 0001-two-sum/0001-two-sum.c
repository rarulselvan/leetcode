/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++) 
        {
            if ( target== nums[i]+nums[j])
            {
                int *ans = (int *) malloc(sizeof(int)*2);
                ans[0] = i;
                ans[1] = j;
                *returnSize=2;
                return ans;
            }
        }
    }
    return NULL;
}