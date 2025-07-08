class Solution 
{
public:
    vector<int> nextGreaterElements(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;

        // Double the array (since it is a circular array)
        for (int i = 2 * n - 1; i >= 0; i--) 
        {
            // Pop out  the elements from the stack that cannot be the next greater element for the current value
            while (!stk.empty() && stk.top() <= arr[i % n]) 
                stk.pop();

            // If the stack is not empty, the top element is the next greater element for the current  element to be added into the stack
            if (!stk.empty() && i < n ) 
                res[i] = stk.top();
    
            // Push the current element onto the stack
            stk.push(arr[i % n]);
        }
        return res;
    }
};