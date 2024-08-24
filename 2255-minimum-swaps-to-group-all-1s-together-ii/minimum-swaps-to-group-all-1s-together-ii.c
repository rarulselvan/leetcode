int minSwaps(int* nums, int numsSize)
 {
    int k = 0;
    for (int i = 0; i < numsSize; i++) 
    {
        k += nums[i];
    }
    
    int cnt = 0;
    for(int i = 0; i < k; i++) 
    {
        cnt += nums[i];
    }
    
    int mx = cnt;
    for (int i = k; i < numsSize + k; i++)
    {
        cnt += nums[i % numsSize] - nums[(i - k + numsSize) % numsSize];
        if (cnt > mx) {
            mx = cnt;
        }
    }
    
    return k - mx;
}