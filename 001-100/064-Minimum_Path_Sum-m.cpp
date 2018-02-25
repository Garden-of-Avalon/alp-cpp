// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Example 1:

// [[1,3,1],
//  [1,5,1],
//  [4,2,1]]

// Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the
// sum.

class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        // assume we can modify grid
        int m = grid.size(), n = m ? grid[0].size() : 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (i && j)
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                else if (!i && j)
                    grid[i][j] += grid[i][j - 1];
                else if (i && !j)
                    grid[i][j] += grid[i - 1][j];

        return !m && !n ? 0 : grid[m - 1][n - 1];
    }
};