// Follow up for N-Queens problem.

// Now, instead outputting board configurations, return the total number of
// distinct solutions.

class Solution {
  public:
    int totalNQueens(int n) {
        int cnt = 0;
        vector<vector<char>> board(n, vector<char>(n, '.'));
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
                ++cnt;
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

        return cnt;
    }
};