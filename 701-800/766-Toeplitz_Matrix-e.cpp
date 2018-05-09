// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the
// same element.

// Now given an M x N matrix, return True if and only if the matrix is Toeplitz.

// Example 1:

// Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
// Output: True
// Explanation:
// 1234
// 5123
// 9512

// In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2,
// 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the
// answer is True. Example 2:

// Input: matrix = [[1,2],[2,2]]
// Output: False
// Explanation:
// The diagonal "[1, 2]" has different elements.
// Note:

// matrix will be a 2D array of integers.
// matrix will have a number of rows and columns in range [1, 20].
// matrix[i][j] will be integers in range [0, 99].

class Solution {
  public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        // int r, c; // row , columns
        // if ((r = matrix.size()) < 2 || (c = matrix[0].size()) < 2)
        //     return true;
        int r = matrix.size(), c = matrix[0].size();

        for (int i = 1; i < r; ++i)
            for (int j = 1; j < c; ++j)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;

        return true;
    }
};

class Solution {
  public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        int r, c; // row , columns
        if ((r = matrix.size()) < 2 || (c = matrix[0].size()) < 2)
            return true;

        for (int i = 1; i < r; ++i)
            for (int j = c - 2; j >= 0; --j)
                if (matrix[i - 1][j] != matrix[i][j + 1])
                    return false;

        return true;
    }
};

class Solution {
  public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        int r, c; // row , columns
        if ((r = matrix.size()) < 2 || (c = matrix[0].size()) < 2)
            return true;
        // define check[i][j] is true if check[i - 1][j] and check[i][j + 1] are
        // both true and matrix[i - 1][j] == matrixM[i][j + 1]
        vector<vector<bool>> check(r, vector<bool>(c));
        // first line
        fill(check[0].begin(), check[0].end(), true);
        // last column
        for_each(check.begin(), check.end(),
                 [](auto &cr) { cr.back() = true; });

        for (int i = 1; i < r; ++i)
            for (int j = c - 2; j >= 0; --j)
                if (check[i - 1][j] && check[i][j + 1] &&
                    matrix[i - 1][j] == matrix[i][j + 1])
                    check[i][j] = true;
                else
                    return false;

        return true;
    }
};

// TLE
// class Solution {
//     // check from bottom left to top right
//     bool check(const vector<vector<int>> &M, int i, int j) {
//         if (i == 0 || j == M[0].size() - 1)
//             return true;
//         return check(M, i - 1, j) && check(M, i, j + 1) &&
//                M[i - 1][j] == M[i][j + 1];
//     }

//   public:
//     bool isToeplitzMatrix(vector<vector<int>> &matrix) {
//         if (matrix.size() < 2 || matrix[0].size() < 2)
//             return true;
//         else
//             return check(matrix, matrix.size() - 1, 0);
//     }
// };