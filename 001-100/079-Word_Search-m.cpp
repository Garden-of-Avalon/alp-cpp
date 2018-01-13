//  Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where
// "adjacent" cells are those horizontally or vertically neighboring. The same
// letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false

// use set<pair> not fast
class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = m > 0 ? board[0].size() : 0;

        function<bool(int, int, int, set<pair<int, int>> &)> check =
            [&](int x, int y, int w, set<pair<int, int>> &used) {
                if (w == word.size())
                    return true;

                if (x < 0 || x >= m || y < 0 || y >= n)
                    return false;

                if (!used.insert({x, y}).second)
                    return false;

                if (board[x][y] == word[w] && (check(x - 1, y, w + 1, used) ||
                                               check(x + 1, y, w + 1, used) ||
                                               check(x, y - 1, w + 1, used) ||
                                               check(x, y + 1, w + 1, used)))
                    return true;
                else {
                    used.erase({x, y});
                    return false;
                }
            };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                set<pair<int, int>> used;
                if (check(i, j, 0, used))
                    return true;
            }

        return false;
    }
};

// use  vector<vector<bool>>
class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = m > 0 ? board[0].size() : 0;

        // used pad m × n, one pad is enough
        vector<vector<bool>> used(m, vector<bool>(n, false));

        function<bool(int, int, int)> check = [&](int x, int y, int w) {
            if (w == word.size())
                return true;

            if (x < 0 || x >= m || y < 0 || y >= n)
                return false;

            if (used[x][y] == true)
                return false;

            used[x][y] = true;

            if (board[x][y] == word[w] &&
                (check(x - 1, y, w + 1) || check(x + 1, y, w + 1) ||
                 check(x, y - 1, w + 1) || check(x, y + 1, w + 1)))
                return true;
            else {
                // reset used pad
                used[x][y] = false;
                return false;
            }
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (check(i, j, 0))
                    return true;

        return false;
    }
};

// more memory saving way
class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = m > 0 ? board[0].size() : 0;

        function<bool(int, int, int)> check = [&](int x, int y, int w) {
            if (w == word.size())
                return true;

            if (x < 0 || x >= m || y < 0 || y >= n)
                return false;

            if (board[x][y] != word[w])
                return false;

            // somehow like lock
            board[x][y] ^= 255;
            bool ret = check(x - 1, y, w + 1) || check(x + 1, y, w + 1) ||
                       check(x, y - 1, w + 1) || check(x, y + 1, w + 1);
            board[x][y] ^= 255;

            return ret;

        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (check(i, j, 0))
                    return true;

        return false;
    }
};