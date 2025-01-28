class Solution {
public:
    int findMaxFish(std::vector<std::vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        int maxFishCount = 0;
        // Iterate over each cell in the grid.
        for (int i = 0; i < numRows; ++i) 
        {
            for (int j = 0; j < numCols; ++j) 
            {
                // If cell is not visited and there are fishes, perform DFS.
                if (grid[i][j]) 
                {
                    maxFishCount = std::max(maxFishCount, depthFirstSearch(grid, i, j));
                }
            }
        }
        return maxFishCount; // Return the maximum number of fishes in a connected region.
    }

    int depthFirstSearch(std::vector<std::vector<int>>& grid, int row, int col) {
        int fishCount = grid[row][col];
        grid[row][col] = 0; // Mark as visited by setting to 0.

        // Directions: up, right, down, left
        int directions[5] = {-1, 0, 1, 0, -1};//explore all direction in DFS
        for (int k = 0; k < 4; k++) 
        {
            //For each k, the corresponding pair (directions[k], directions[k + 1]) gives the row and column offset.
            int newRow = row + directions[k];
            int newCol = col + directions[k + 1];

            /*
            Up: (-1, 0)
            Right: (0, 1)
            Down: (1, 0)
            Left: (0, -1)
            */

            // Check if the new coordinates are valid and not visited.
            //if it is water means it is not visited
            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] /*needs to be not visited*/) 
            {
                fishCount += depthFirstSearch(grid, newRow, newCol);
            }
        }
        return fishCount;
    }
};
