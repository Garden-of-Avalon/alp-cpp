// Given a matrix of m x n elements (m rows, n columns), return all elements of
// the matrix in spiral order.
// For example,
// Given the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0;
        while (m > 0 && n > 0) {
            if (m == 1 && n == 1) {
                res.push_back(matrix[i][j]);
                break;
            }

            // left to right
            for (int i1 = 0; i1 < n - 1; ++i1)
                res.push_back(matrix[i][j++]);

            if (m == 1) {
                res.push_back(matrix[i][j]);
                break;
            }

            // up to down
            for (int i2 = 0; i2 < m - 1; ++i2)
                res.push_back(matrix[i++][j]);

            if (n == 1) {
                res.push_back(matrix[i][j]);
                break;
            }

            // right to left
            for (int i3 = 0; i3 < n - 1; ++i3)
                res.push_back(matrix[i][j--]);

            // down to up
            for (int i4 = 0; i4 < m - 1; ++i4)
                res.push_back(matrix[i--][j]);

            ++i;
            ++j;

            m -= 2;
            n -= 2;
        }

        return res;
    }
};