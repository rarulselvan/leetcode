int max(int a, int b) { return (a > b) ? a : b; }

// Returns LIS of subarray ending with index i.
int lisEndAtI(int arr[], int i, int *dp)
{
    // Base case
    if (i == 0)
        return 1;
    if(dp[i]!=-1)
        return dp[i];

    // Consider all elements on left of i,
    // recursively compute LISs ending with 
    // them and consider the largest
    int mx = 1;
    for (int prev = 0; prev < i; prev++)
        if (arr[prev] < arr[i])
            mx = max(mx, 1+lisEndAtI(arr, prev, dp));

    dp[i]=mx;
    return mx;
}

int lengthOfLIS(int* nums, int n) 
{
    int res = 1;
    int *dp=(int *)malloc(sizeof(int)* (n));
    for(int j=0; j< n; j++)
        dp[j]=-1;

    for (int i = 1; i < n; i++)
        res = max(res, lisEndAtI(nums, i, dp));
    return res;
}