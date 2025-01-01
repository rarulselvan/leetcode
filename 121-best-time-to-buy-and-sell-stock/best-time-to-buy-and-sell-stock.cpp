class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minSoFar = prices[0];
        int maximum = 0;
    
        for(int i: prices)
        {
            // Update the minimum value seen so
            // far if we see smaller
            minSoFar = min(minSoFar, i);
        
            // Update result if we get more profit                
            maximum = max(maximum, i - minSoFar);
        }
        return maximum;
    }
};