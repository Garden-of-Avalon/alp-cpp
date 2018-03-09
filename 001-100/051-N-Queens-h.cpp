// The n-queens puzzle is the problem of placing n queens on an n×n chessboard
// such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space
// respectively.

// For example,
// There exist two distinct solutions to the 4-queens puzzle:

// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

class Solution {
    // we can use bitset to save memory
    unordered_set<int> cols, rows, ul_br, bl_ur;
    // up left to bottom right, bottom left to up right

    bool check(const int &i, const int &j) {
        if (rows.find(i) != rows.end() || cols.find(j) != cols.end() ||
            ul_br.find(i - j) != ul_br.end() ||
            bl_ur.find(i + j) != bl_ur.end())
            return false;
        return true;
    }

    void set_use(const int &i, const int &j) {
        rows.emplace(i);
        cols.emplace(j);
        ul_br.emplace(i - j);
        bl_ur.emplace(i + j);
    }

    void reset_use(const int &i, const int &j) {
        rows.erase(i);
        cols.erase(j);
        ul_br.erase(i - j);
        bl_ur.erase(i + j);
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> board(n, string(n, '.'));

        function<void(int)> backtrack = [&](int row) {
            if (row == n)
                ret.push_back(board);
            else
                for (int col = 0; col < n; ++col) {
                    if (check(row, col)) {
                        board[row][col] = 'Q';
                        set_use(row, col);

                        backtrack(row + 1);

                        reset_use(row, col);
                        board[row][col] = '.';
                    }
                }
        };

        backtrack(0);

        return ret;
    }
};

// optimization
class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n), rows(n), ul_br(2 * n - 1), bl_ur(2 * n - 1);

        auto check = [&](const int &i, const int &j) {
            return !(rows[i] || cols[j] || ul_br[i - j + n - 1] ||
                     bl_ur[i + j]);
        };

        auto set_reset_use = [&](const int &i, const int &j) {
            rows[i] = !rows[i];
            cols[j] = !cols[j];
            ul_br[i - j + n - 1] = !ul_br[i - j + n - 1];
            bl_ur[i + j] = !bl_ur[i + j];
        };

        function<void(int)> backtrack = [&](int row) {
            if (row == n)
                ret.push_back(board);
            else
                for (int col = 0; col < n; ++col)
                    if (check(row, col)) {
                        board[row][col] = 'Q';
                        set_reset_use(row, col);

                        backtrack(row + 1);

                        set_reset_use(row, col);
                        board[row][col] = '.';
                    }
        };

        backtrack(0);

        return ret;
    }
};
