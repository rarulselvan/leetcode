class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minimumPriceSoFar = prices[0];
        int maxProfit = 0;
    
        for(int i: prices)
        {
            // Update the minimum value seen so
            // far if we see smaller
            minimumPriceSoFar = min(minimumPriceSoFar, i);
        
            // Update result if we get more profit 
            int profit= i-minimumPriceSoFar;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};