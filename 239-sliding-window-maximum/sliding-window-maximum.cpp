/*class Solution
{
public:

    vector < int > maxSlidingWindow(vector < int > & nums, int k)
    {
        deque < int > dq;
        vector < int > ans;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (dq.front() == i - k) 
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

            dq.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};*/

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int> windowIndices;  // Deque to store indices of elements in the current window
        vector<int> ans;     // Vector to store the maximum value for each window

        for (int i = 0; i < nums.size(); ++i) 
        {
    
            if ( windowIndices.front()==i-k)
                windowIndices.pop_front();        // Remove indices of elements not in the current window
            
            // Maintain the elements in decreasing order in the deque
            // Pop elements from the back that are less than or equal to the current element
            while (!windowIndices.empty() && nums[windowIndices.back()] <= nums[i]) 
                windowIndices.pop_back();
            
            // Push current element's index onto the deque
            windowIndices.push_back(i);
          
            // If we've reached the end of the first window, record the max for the current window
            if (i >= k - 1)
                ans.push_back(nums[windowIndices.front()]);
        }
      
        return ans;  // Return the list of maximum values
    }
};