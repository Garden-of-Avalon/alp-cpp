// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows, {1});

        for (int i = 1; i < numRows; ++i) {
            for (int j = 1; j < i; ++j) 
                ret[i].push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
            ret[i].push_back(1);
        }

        return ret;
    }
};