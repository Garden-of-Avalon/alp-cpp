//  Given a m x n matrix, if an element is 0, set its entire row and column to
//  0. Do it in place.

// click to show follow up.
// Follow up:

// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

// O(1) space
class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        // use first row contain 0 to record zero columns
        int first_0_row = -1;
        for (int i = 0; i < matrix.size(); ++i) {
            bool mark = false; // mark this row contain 0 or not

            for (int j = 0; j < matrix[0].size(); ++j)
                if (matrix[i][j] == 0)
                    if (first_0_row == -1) {
                        first_0_row = i;
                        break; // goto next i
                    } else {
                        mark = true;
                        matrix[first_0_row][j] = 0;
                    }

            if (mark)
                for (int k = 0; k < matrix[0].size(); ++k)
                    matrix[i][k] = 0;
        }

        // no 0
        if (first_0_row == -1)
            return;

        // set all columns from record in first_0_row
        for (int j = 0; j < matrix[0].size(); ++j)
            if (matrix[first_0_row][j] == 0)
                for (int i = 0; i < matrix.size(); ++i)
                    matrix[i][j] = 0;
            else
                matrix[first_0_row][j] = 0;

        return;
    }
};