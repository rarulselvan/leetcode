class Solution 
{
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinceCount = 0;

            //Lamda function
            function<void(int)> dfs = [&](int city)
            {
                visited[city] = true;
                for (int neighbor = 0; neighbor < n; neighbor++) 
                {
                    if (isConnected[city][neighbor] && !visited[neighbor]) 
                    {
                        dfs(neighbor);
                    }
                }
            };

        for (int city = 0; city < n; city++) 
        {
            if (!visited[city])
            {
                dfs(city);
                ++provinceCount;
            }
        }
        return provinceCount;
    }
};