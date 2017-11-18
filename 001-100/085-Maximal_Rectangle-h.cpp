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
        if (!matrix.size())
            return 0;
        int h = matrix.size(), w = matrix[0].size();

        // row width, height
        vector<int> ht(w + 1, 0);
        // use w + 1 is for convenience of last compare
        // see Mark#1

        int ret = 0;
        for (int i = 0; i < h; ++i) {
            stack<int> rIndexes;
            for (int j = 0; j < w; ++j)
                if (matrix[i][j] == '1')
                    ++ht[j];
                else
                    ht[j] = 0;

            for (int j = 0; j < w + 1; ++j) {
                // Mark#1
                // for height 1 2 3 4 5, h[j]==0
                // calculate and compare 5×1, 4×2, 3×3, 2×4, 1×5
                while (!rIndexes.empty() && ht[j] < ht[rIndexes.top()]) {
                    int pretop = rIndexes.top();
                    rIndexes.pop();
                    ret = max(ret,
                              ht[pretop] * (rIndexes.empty()
                                                ? j
                                                : j - rIndexes.top() - 1));
                }
                rIndexes.push(j);
            }
        }

        return ret;
    }
};