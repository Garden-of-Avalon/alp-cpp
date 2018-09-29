// Given a matrix of M x N elements (M rows, N columns), return all elements of
// the matrix in diagonal order as shown in the below image.

// Example:
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output:  [1,2,4,7,5,3,6,8,9]

// Note:
// The total number of elements of the given matrix will not exceed 10,000.

class Solution {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        if (matrix.empty())
            return {};

        if (matrix.size() == 1)
            return matrix[0];

        int m = matrix.size(), n = matrix[0].size();

        int i = 0, j = 0;
        pair<int, int> step{-1, 1};
        vector<int> ret{matrix[i][j]};

        while (i != m - 1 || j != n - 1) {
            if ((i == 0 || j == n - 1) && step.first == -1) {
                j == n - 1 ? ++i : ++j;
                swap(step.first, step.second);
            } else if ((j == 0 || i == m - 1) && step.first == 1) {
                i == m - 1 ? ++j : ++i;
                swap(step.first, step.second);
            } else {
                i += step.first;
                j += step.second;
            }
            ret.push_back(matrix[i][j]);
        }

        return ret;
    }
};
