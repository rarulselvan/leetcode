class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int total_gas = 0, total_cost = 0, tank = 0, start_index = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            tank += gas[i] - cost[i];
            
            // If tank is negative, we cannot reach the next station
            if (tank < 0)
            {
                // Which means if you start from this station you cannot reach the next station hence this station can't be the starting point
                start_index = i + 1;  // Set next station as the new start
                tank = 0;  // Reset tank
            }
        }
        //compare the total cost and the total fuel
        return (total_gas >= total_cost) ? start_index : -1;
    }
};