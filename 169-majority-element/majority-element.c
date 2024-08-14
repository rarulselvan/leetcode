/*int majorityElement(int* nums, int numsSize)
{
    int maxCount=0;
    int element=0;
    for(int i=0; i<numsSize; i++)
    {
        int count=0;
        //Compare the array elemets to entire array, repeat for all array elements
        for(int j=0; j<numsSize; j++)
        {
            if(nums[i]==nums[j])
                count++;
        }
        if(count>maxCount)
        {
            maxCount=count;
            element=nums[i];
        }
    }
    if(maxCount > (numsSize/2))
        return element;
    else
        return -1;
}*/
int majorityElement(int* nums, int numsSize)
{
    int count = 0;
    int res = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int num = nums[i];
        if (count == 0)
        {
            res = num;
        } 
        count += (num == res) ? 1 : -1;
    }
    return res;
}