class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        parent = list(range(m * n))  # Initialize parent list for disjoint set
        grid = [[0] * n for _ in range(m)]  # Initialize the grid with all water (0s)
      
        # Helper function to check if a position is within bounds and is land
        def is_valid_land(i, j):
            return 0 <= i < m and 0 <= j < n and grid[i][j] == 1
      
        # Find function for disjoint set with path compression
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])  # Path compression
            return parent[x]
      
        # List to record the number of islands after each addLand operation
        num_islands_after_each_add_land = []
        current_num_islands = 0  # Current number of islands
      
        for i, j in positions:
            index = i * n + j  # Convert the 2D position to a 1D index for the disjoint set
          
            # If the land is already added, append the current number of islands and skip
            if grid[i][j] == 1:
                num_islands_after_each_add_land.append(current_num_islands)
                continue
              
            grid[i][j] = 1  # Mark the position as land
            current_num_islands += 1  # Increment island count by one
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:  # Check surrounding positions
                neighbor_i = i + dx
                neighbor_j = j + dy
              
                # If neighbor is valid land, merge sets if they are not already part of the same set
                if is_valid_land(neighbor_i, neighbor_j):
                    neighbor_index = neighbor_i * n + neighbor_j
                    root = find(index)
                    neighbor_root = find(neighbor_index)
                    if root != neighbor_root:
                        parent[root] = neighbor_root  # Union operation
                        current_num_islands -= 1  # If two lands are connected, decrement island count
                      
            # Append the updated number of islands after this addLand operation
            num_islands_after_each_add_land.append(current_num_islands)
      
        return num_islands_after_each_add_land