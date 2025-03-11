class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> stk;
        stk.push(-1);
        int max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            while (stk.top() != -1 and heights[stk.top()] >= heights[i]) {
                int current_height = heights[stk.top()];
                stk.pop();
                int current_width = i - stk.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }
            stk.push(i);
        }
        while (stk.top() != -1 )
        {
            int current_height = heights[stk.top()];
            stk.pop();
            int current_width = heights.size() - stk.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }

        return max_area;
    }
};
/*lass Solution {
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
                cout <<maxArea<<endl;
            }
            cout <<"push "<<i<<endl;
            stack.push(i);
        }
        
        return maxArea;
    }
}; */