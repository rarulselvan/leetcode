class Solution 
{
public:
    vector<int> parent, rank;

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false; // Cycle detected

        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) 
    {
        if (edges.size() != n - 1) 
            return false; // Tree must have exactly n-1 edges

        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i; // Initialize parent array

        for (auto& edge : edges) 
        {
            if (!unite(edge[0], edge[1])) 
                return false; // Cycle detected
        }
        return true; // Valid tree
    }
};