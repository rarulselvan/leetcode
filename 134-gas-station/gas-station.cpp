class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int totalGas = 0, totalCost = 0, tank = 0, startStation = 0;
        
        for (int i = 0; i < gas.size(); i++)
         {
            totalGas    += gas[i];
            totalCost   += cost[i];
            tank        = tank +(gas[i] - cost[i]);
            
            // If tank is negative, we cannot reach the next station
            if (tank < 0)
            {
                // Which means if you start from this station you cannot move forward hence this station can't be the starting point
                startStation = i + 1;  // Set next station as the new start
                tank = 0;  // Reset tank
            }
        }
        //compare the total cost and the total fuel
        return (totalGas >= totalCost) ? startStation : -1;
    }
};