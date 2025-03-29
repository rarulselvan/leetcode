class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size(); 
        vector<int> daysToWait(n); 
        stack<int> stackIndex;

        for (int i = 0; i < n; i++) 
        {
            // Check if the current day's temperature is higher than the temperature at the top of the stack
            while (!stackIndex.empty() &&  temperatures[i] >temperatures[stackIndex.top()]) 
            {
                int previousDayIndex = stackIndex.top(); // Get the index of the day with the lower temperature
                daysToWait[previousDayIndex] = i - previousDayIndex; // Calculate the days to wait
                stackIndex.pop(); // Remove that day from the stack since it's now processed
            } 
            stackIndex.push(i);
        }
        return daysToWait;
    }
};