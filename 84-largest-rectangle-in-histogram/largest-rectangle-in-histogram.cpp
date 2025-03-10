/*class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> st;  // Monotonic increasing stack
        int maxArea = 0;
        heights.push_back(0);  // Sentinel to process remaining bar

        for (int i = 0; i < heights.size(); i++) 
        {
            while (!st.empty() && heights[st.top()] > heights[i]) 
            {
                int height = heights[st.top()];
                cout <<"pop()"<<height<<endl;
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            cout<<"push "<<heights[i]<<" "<<i<<endl;
            st.push(i);
        }
        return maxArea;
    }
};
*/
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int numBars = heights.size();
        std::stack<int> stack;
        int maxArea = 0;
        
        for (int i = 0; i <= numBars; ++i) {
            int height = (i == numBars) ? 0 : heights[i];
            
            while (!stack.empty() && heights[stack.top()] >= height) {
                int h = heights[stack.top()];
                stack.pop();
                int w = stack.empty() ? i : i - stack.top() - 1;
                maxArea = std::max(maxArea, h * w);
            }
            
            stack.push(i);
        }
        
        return maxArea;
    }
};