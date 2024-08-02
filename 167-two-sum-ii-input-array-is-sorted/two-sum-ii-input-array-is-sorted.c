/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

    int first=0;
    int last=numbersSize-1;
    int sum=0;
    *returnSize=0;
    while(first<last)
    {
        sum= numbers[first]+numbers[last];
        printf("%d...%d===", sum,target);
        if(sum<target)
        {
            first++;
        }
        else if(sum>target)
            last--;
        else
        {
            int *ret= (int *)malloc(sizeof(int)*2);
            ret[0]=first+1;
            ret[1]=last+1;
            *returnSize=2;
            return ret;
        }
    }
    return NULL;
}