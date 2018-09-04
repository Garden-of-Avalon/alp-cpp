// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the
// previous row. Example 1:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
// Example 2:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (!m)
            return false;

        int n = matrix[0].size(), len = m * n;

        auto getVal = [&](auto i) -> int & { return matrix[i / n][i % n]; };

        // binary search
        int l = 0, r = len - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = getVal(mid);

            if (midVal == target)
                return true;

            if (midVal < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }
};