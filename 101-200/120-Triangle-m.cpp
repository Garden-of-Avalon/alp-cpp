// Given a triangle, find the minimum path sum from top to bottom. Each step you
// may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]

// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n
// is the total number of rows in the triangle.

// dp
class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<int> ret = triangle.back();

        for (int curr_len = triangle.size() - 1; curr_len > 0; --curr_len)
            for (int i = 0; i < curr_len; ++i)
                ret[i] = min(ret[i], ret[i + 1]) + triangle[curr_len - 1][i];
        // line 3 can result in 3 possible min_results when add with line 4

        return ret[0];
    }
};

// if we can modify triangle
class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        for (int curr_len = triangle.size() - 1; curr_len > 0; --curr_len)
            for (int i = 0; i < curr_len; ++i)
                triangle[curr_len - 1][i] +=
                    min(triangle[curr_len][i], triangle[curr_len][i + 1]);

        return triangle[0][0];
    }
};