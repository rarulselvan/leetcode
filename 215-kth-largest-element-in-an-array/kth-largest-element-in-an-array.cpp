class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        // 2nd arg vector<int> --- elements are stored in vector
        //greater<int >- convert into min q..smallest element is always on top
        priority_queue<int, vector<int>, greater<int>> minQ;
        for (int x : nums)
        {
            minQ.push(x);
            if (minQ.size() > k)
            {
                minQ.pop();
            }
        }
        return minQ.top();
    }
};