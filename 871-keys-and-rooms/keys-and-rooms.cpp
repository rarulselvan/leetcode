class Solution 
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        vector<bool> seen(rooms.size());
        dfs(rooms, 0, seen);

        for(auto x: seen)
        {
            if(x==false)
                return false;
        }
        return true;
    }
    void dfs(const vector<vector<int>>& rooms, int node, vector<bool>& seen) 
    {
        seen[node] = true;
        for (const int child : rooms[node])
        if (!seen[child])
            dfs(rooms, child, seen);
    }
};