// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
// containing only 1's and return its area.
// For example, given the following matrix:
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 6.

class Solution {
  public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int h = matrix.size(), w = matrix[0].size();

        // use w + 1 for convenience of last compare
        vector<int> ht(w + 1, 0);

        int ret = 0;
        for (int i = 0; i < h; ++i) {
            stack<int> cols;
            for (int j = 0; j < w; ++j)
                matrix[i][j] == '0' ? ht[j] = 0 : ++ht[j];

            for (int j = 0; j < w + 1; ++j) {
                // e.g. ht 1 2 3 4 5 0, ht[j] == 0 (j == 5)
                // compare 5×1, 4×2, 3×3, 2×4, 1×5
                while (!cols.empty() && ht[j] < ht[cols.top()]) {
                    int prev = cols.top();
                    cols.pop();
                    ret = max(ret, ht[prev] *
                                       (cols.empty() ? j : j - cols.top() - 1));
                }
                cols.push(j);
            }
        }

        return ret;
    }
};