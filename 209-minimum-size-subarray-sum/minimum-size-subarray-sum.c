int minSubArrayLen(int s, int* nums, int n)
{
    if (n == 0)
        return 0;
    int ans = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
     {
        sum += nums[i];
        printf("sum=%d\n", sum);
        while (sum >= s) 
        {
            //if(sum==s)            
                ans = (ans > ((i- left)+1)) ? ((i - left)+1):ans;
            sum = sum-nums[left]; // remove the left most 
            left++;//and slide the window forward
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}