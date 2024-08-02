int max(int a, int b)
{
    return a>b? a:b;
}
bool canJump(int* nums, int numsSize)
{
    if(numsSize==1)
        return true;
    int mx = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (mx < i)//farthest position that can be reached
        {
            return false;
        }
        mx = max(mx, i + nums[i]); //max position can be rreached from here...
        //that is we are already reached index i from 0
        // so i+the current position capacity to jump...
    }
    return true;
}