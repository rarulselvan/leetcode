class Solution 
{
public:
    bool find132pattern(vector<int>& nums) 
    {
        stack<int>stk;
        int ithValue=INT_MIN; //minimum among three

        // Idea--> start from the right edge and add the elements into stack
        // If the element to be added is less than the top of the stack ...keep adding it
        // Otherwise ..pop the stack until the comparision(above) is true
        // In the "pop" process get the max elements among the popped element

        for(int i=nums.size()-1; i>=0; i--)
        {
            cout << ithValue << " ";
            if(nums[i] <ithValue)
                return true;
            while(!stk.empty() && nums[i] > stk.top())
            {
                ithValue=stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};