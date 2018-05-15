// You have a list of points in the plane. Return the area of the largest
// triangle that can be formed by any 3 of the points.

// Example:
// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// Output: 2
// Explanation:
// The five points are show in the figure below. The red triangle is the
// largest.

// Notes:

// 3 <= points.length <= 50.
// No points will be duplicated.
//  -50 <= points[i][j] <= 50.
// Answers within 10^-6 of the true value will be accepted as correct.

// since this is still O(n^3), brute force would be also ok
class Solution {
    double cal(const vector<vector<int>> &tri) {
        // abs(x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1)) / 2;
        return 0.5 * abs(tri[0][0] * (tri[1][1] - tri[2][1]) +
                         tri[1][0] * (tri[2][1] - tri[0][1]) +
                         tri[2][0] * (tri[0][1] - tri[1][1]));
    }

  public:
    double largestTriangleArea(vector<vector<int>> &points) {
        double ret = -1;
        vector<vector<int>> tri;

        auto backtrack = [&](auto &&self, int st) {
            if (tri.size() == 3) {
                ret = max(cal(tri), ret);
                return;
            }
            for (int i = st; i < points.size(); ++i) {
                tri.push_back(points[i]);
                self(self, st + 1);
                tri.pop_back();
            }
        };

        backtrack(backtrack, 0);

        return ret;
    }
};
