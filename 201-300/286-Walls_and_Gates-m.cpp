// You are given a m x n 2D grid initialized with these three possible values.

// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to
// represent INF as you may assume that the distance to a gate is less than
// 2147483647. Fill each empty room with the distance to its nearest gate. If it
// is impossible to reach a gate, it should be filled with INF.

// Example:

// Given the 2D grid:

// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// After running your function, the 2D grid should be:

//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4

// slightly different from 317
class Solution {
  public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        if (rooms.empty() || rooms[0].empty())
            return;

        int m = rooms.size(), n = rooms[0].size();
        vector<int> delta = {0, 1, 0, -1, 0};

        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (rooms[i][j] == 0)
                    q.emplace(i, j);

        while (!q.empty()) {
            auto pos = q.front();
            q.pop();

            for (int ii = 0; ii < 4; ++ii) {
                int x = pos.first + delta[ii], y = pos.second + delta[ii + 1];

                // if rooms[x][y] < INT_MAX, it must be smallest level
                if (x < 0 || x >= m || y < 0 || y >= n ||
                    rooms[x][y] != INT_MAX)
                    continue;

                rooms[x][y] = rooms[pos.first][pos.second] + 1;

                q.emplace(x, y);
            }
        }
    }
};