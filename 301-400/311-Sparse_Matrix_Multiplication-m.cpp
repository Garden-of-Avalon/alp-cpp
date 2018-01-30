// Given two sparse matrices A and B, return the result of AB.

// You may assume that A's column number is equal to B's row number.

// Example:

// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]

// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]

//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |

class Solution {
  public:
    vector<vector<int>> multiply(vector<vector<int>> &A,
                                 vector<vector<int>> &B) {
        int cr = B.size(); // column number of A, row number of B

        // if(!cr)
        //     return {};

        vector<vector<int>> ret(A.size(), vector<int>(B[0].size()));

        for (int i = 0; i < ret.size(); ++i)
            for (int k = 0; k < cr; ++k)
                if (A[i][k])
                    for (int j = 0; j < ret[0].size(); ++j)
                        ret[i][j] += A[i][k] * B[k][j];
        // cache optimized, ++j go through horizontally

        return ret;
    }
};