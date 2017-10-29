// Given a 2d grid map of '1's (land) and '0's (water), count the number of
// islands. An island is surrounded by water and is formed by connecting
// adjacent lands horizontally or vertically. You may assume all four edges of
// the grid are all surrounded by water.
// Example 1:
// 11110
// 11010
// 11000
// 00000
// Answer: 1
// Example 2:
// 11000
// 11000
// 00100
// 00011
// Answer: 3
// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test
// cases.

class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        int a = grid.size(), b = a ? grid[0].size() : 0;

        int cnt = 0;

        function<void(int, int)> DFSmark = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= a || j >= b || grid[i][j] == '0')
                return;
            grid[i][j] = '0';
            DFSmark(i + 1, j);
            DFSmark(i - 1, j);
            DFSmark(i, j + 1);
            DFSmark(i, j - 1);
        };

        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b; ++j)
                if (grid[i][j] == '1') {
                    DFSmark(i, j);
                    ++cnt;
                }

        return cnt;
    }
};