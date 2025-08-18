class Solution 
{
public:

    vector<int> maxSlidingWindow(vector<int>& arr, int k) 
    {
        int n = arr.size();

        vector<int> res;

        // to store the max value
        priority_queue<pair<int, int> > heap;

        // Initialize the heap with the first k elements
        for (int i = 0; i < k; i++)
            heap.push({ arr[i], i });//push element and the index together

        // The maximum element in the first window
        res.push_back(heap.top().first);

        // Process the remaining elements
        for (int i = k; i < arr.size(); i++) {

            // Add the next element
            heap.push({ arr[i], i });

            // Remove top element(s) that are outside the current window...heap size may grow beyond the sliding window size
            //Even though the heap may grow beyond k, you lazy-remove old elements only when they appear at the top.
            while (heap.top().second <= i - k)
                heap.pop();

            // The maximum element in the current window
            res.push_back(heap.top().first);
        }

        return res;
    } 
};
//Monototonic stack implementation

/*
class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int> windowIndices;  // Deque to store indices of elements in the current window
        vector<int> ans;     // Vector to store the maximum value for each window

        for (int i = 0; i < nums.size(); ++i) 
        {
            if( windowIndices.front()==i-k)
                windowIndices.pop_front();        // Remove indices of elements not in the current window
            
            // Maintain the elements in decreasing order in the deque, maximum value will be there in the front 
            // Pop elements from the back that are less than or equal to the current element
            while (!windowIndices.empty() && nums[windowIndices.back()] <= nums[i]) 
                windowIndices.pop_back();
            
            // Push current element's index onto the deque
            windowIndices.push_back(i);
          
            // If we've reached the end of the first window, record the max for the current window
            if (i >= k-1 )
            {
                cout <<i<<" "<<k<<endl;
                ans.push_back(nums[windowIndices.front()]);
            }
        }
    
        return ans;  // Return the list of maximum values
    }
};
*/