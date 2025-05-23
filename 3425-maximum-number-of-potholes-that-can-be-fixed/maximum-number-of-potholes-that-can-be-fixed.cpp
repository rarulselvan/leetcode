class Solution 
{
public:
    int maxPotholes(string road, int budget) 
    {
        vector<int> potholeGrps;
        int k = 0;

        // Collect consecutive pothole counts
        for (char x : road)
        {
            if (x == 'x')
                k++;
            else if (k > 0)
            {
                potholeGrps.push_back(k);
                k = 0;
            }
        }
        if (k > 0) // Capture trailing potholes...x..xxx...(x)--> this x need to be processed
            potholeGrps.push_back(k);

        // Sort pothole segments in ascending order (smallest cost to repair first)
        sort(potholeGrps.rbegin(), potholeGrps.rend());
        for(auto x: potholeGrps)
            cout <<x<<" ";

        int repaired = 0;
        for (int group : potholeGrps) 
        {
            if (group+1 <= budget) 
            {
                repaired += group;
                budget -= group + 1;
            }
            else if (budget > 0)
            {
                repaired += budget - 1;  // Partial repair
                break;
            }
            //if (budget <= 0) break;
        }
        return repaired;
    }
};