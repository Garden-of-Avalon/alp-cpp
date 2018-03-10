// Given an integer n, generate a square matrix filled with elements from 1 to
// n2 in spiral order.

// For example,
// Given n = 3,
// You should return the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));

        int nn = n * n, ii = 1, curr_len = n, r = 0, c = -1;

        while (ii <= nn) {
            // left -> right
            for (int i = 0; i < curr_len; ++i)
                ret[r][++c] = ii++;

            --curr_len;

            // up -> down
            for (int j = 0; j < curr_len; ++j)
                ret[++r][c] = ii++;

            // right -> left
            for (int i = 0; i < curr_len; ++i)
                ret[r][--c] = ii++;

            --curr_len;

            // down -> up
            for (int j = 0; j < curr_len; ++j)
                ret[--r][c] = ii++;
        }

        return ret;
    }
};