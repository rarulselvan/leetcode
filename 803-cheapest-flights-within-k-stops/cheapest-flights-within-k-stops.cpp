class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int INF = 0x3f3f3f3f; // Define an "infinity" value for initial distances.
        vector<int> distances(n, INF); // Initialize all distances to "infinity" except the source.
        vector<int> previousIterationDistances; // Used to store distances from the previous iteration.
        distances[src] = 0; // The distance from the source to itself is always 0.

        // Run the Bellman-Ford algorithm for K+1 iterations because you can have at most K stops in between,
        // which translates to K+1 edges in the shortest path.
        for (int i = 0; i <=K; ++i) {
            // Make a copy of the current state of distances before this iteration.
            previousIterationDistances = distances;

            // For each edge in the graph, try to relax the edge and update the distance to the destination node
            for (const auto& flight : flights) {
                int from = flight[0], to = flight[1], price = flight[2];
              
                // Relaxation step: If the current known distance to 'from' plus the edge weight
                // to 'to' is less than the currently known distance to 'to', update it.
                if (previousIterationDistances[from] < INF) {
                    distances[to] = min(distances[to], previousIterationDistances[from] + price);
                }
            }
        }

        // After K+1 iterations, if the distance to the destination is still "infinity", no such path exists;
        // otherwise, return the shortest distance to the destination.
        return distances[dst] == INF ? -1 : distances[dst];
    }
};