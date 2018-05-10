// Given a 2D integer matrix M representing the gray scale of an image, you need
// to design a smoother to make the gray scale of each cell becomes the average
// gray scale (rounding down) of all the 8 surrounding cells and itself. If a
// cell has less than 8 surrounding cells, then use as many as you can.

// Example 1:
// Input:
// [[1,1,1],
//  [1,0,1],
//  [1,1,1]]
// Output:
// [[0, 0, 0],
//  [0, 0, 0],
//  [0, 0, 0]]
// Explanation:
// For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
// For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
// For the point (1,1): floor(8/9) = floor(0.88888889) = 0
// Note:
// The value in the given matrix is in the range of [0, 255].
// The length and width of the given matrix are in the range of [1, 150].

class Solution {
  public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        vector<vector<int>> ret = M;

        auto cal = [&](int i, int j) -> int {
            int cnt = 0, color = 0;
            for (int a = 0; a < 9; ++a) {
                int r = i - 1 + a / 3, c = j - 1 + a % 3;
                if (r < 0 || r == M.size() || c < 0 || c == M[0].size())
                    continue;
                ++cnt;
                color += M[r][c];
            }
            return color / cnt;
        };

        for (int i = 0; i < M.size(); ++i)
            for (int j = 0; j < M[0].size(); ++j)
                ret[i][j] = cal(i, j);

        return ret;
    }
};