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
        while (sum >= s) 
        {
            ans = (ans < (i + 1 - left)) ? ans : (i + 1 - left);
            sum -= nums[left++];
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}