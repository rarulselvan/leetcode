class Solution 
{
public:
    int gcd(int a, int b) 
   {     return b == 0 ? a : gcd(b, a % b);}

    int maxPoints(vector<vector<int>>& points) 
    {
        int numPoints = points.size();
        int maxPointsOnLine = 1; // Initialize the maximum with 1
    
        for (int i = 0; i < numPoints; i++) 
        {
            int x1 = points[i][0], y1 = points[i][1];
            unordered_map<string, int> slopeCount; // Map to keep track of slope counts

            for (int j = i + 1; j < numPoints; ++j) 
            {
                int x2 = points[j][0], y2 = points[j][1]; // Coordinates for the second point
                int deltaX = x2 - x1, deltaY = y2 - y1; // Differences in x and y coordinates (components of the slope)
                int gcdSlope = gcd(deltaX, deltaY); // Calculate GCD to standardize the slope

                // Create a unique key for the slope by concatenating deltaX and deltaY divided by their GCD
                string slopeKey = to_string(deltaX / gcdSlope) + "." + to_string(deltaY / gcdSlope);
                slopeCount[slopeKey]++;

                // Update maxPointsOnLine if the current slope has more points than the maximum recorded so far
                maxPointsOnLine = max(maxPointsOnLine, slopeCount[slopeKey] + 1);
            }
        }
        return maxPointsOnLine; // Return the maximum number of points on a line
    }
};

