// You want to build a house on an empty land which reaches all buildings in the
// shortest amount of distance. You can only move up, down, left and right. You
// are given a 2D grid of values 0, 1 or 2, where:

// Each 0 marks an empty land which you can pass by freely.
// Each 1 marks a building which you cannot pass through.
// Each 2 marks an obstacle which you cannot pass through.
// Example:

// Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

// 1 - 0 - 2 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0

// Output: 7

// Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at
// (0,2), the point (1,2) is an ideal empty land to build a house, as the total
// travel distance of 3+3+1=7 is minimal. So return 7.

// Note:
// There will be at least one building. If it is not possible to build such
// house according to the above rules, return -1.

class Solution {
  public:
    int shortestDistance(vector<vector<int>> grid) {
        int m = grid.size(), n = grid[0].size();
        int delta[] = {0, 1, 0, -1, 0};

        int bCnt = 0, ret = INT_MAX;

        for (auto &row : grid)
            for (auto &item : row)
                if (item) {
                    if (item == 1)
                        ++bCnt;
                    item = -item;
                }

        // zero means originally, grid[i][j] == 0
        // after processing, zbCnt[i][j] == bCnt
        // means we can use this pt as potential result pos
        auto zbCnt = grid;

        auto bfs_fromij = [&](const int &i, const int &j) {
            queue<pair<int, int>> q;
            q.emplace(i, j);

            vector<bool> visited(m * n);

            auto processChilds = [&](const auto &pt, const int &level) {
                // 4 childs
                for (int d = 0; d < 4; ++d) {
                    int x = pt.first + delta[d], y = pt.second + delta[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] >= 0 &&
                        !visited[x * n + y]) {
                        ++zbCnt[x][y];
                        grid[x][y] += level;

                        if (zbCnt[x][y] == bCnt)
                            ret = min(ret, grid[x][y]);

                        visited[x * n + y] = true;
                        q.emplace(x, y);
                    }
                }
            };

            // real bfs process
            int level = 0;
            while (!q.empty()) {
                int sz = q.size();
                ++level;
                for (int k = 0; k < sz; ++k) {
                    auto pt = q.front();
                    q.pop();
                    processChilds(pt, level);
                }
            }
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == -1)
                    bfs_fromij(i, j);

        return ret == INT_MAX ? -1 : ret;
    }
};