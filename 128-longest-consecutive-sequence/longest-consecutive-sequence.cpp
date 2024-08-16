class Solution {
public:
    int longestConsecutive(vector<int>& a) 
{
    int n = a.size();
    if (n == 0) return 0;
        int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) 
    {
        if (a[i] - 1 == lastSmaller) 
        {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller)
        {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}
};