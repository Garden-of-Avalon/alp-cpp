// Given n points on a 2D plane, find the maximum number of points that lie on
// the same straight line.

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    int gcd(int x, int y) {
        if (!y)
            return x;
        else
            return gcd(y, x % y);
    }

  public:
    int maxPoints(vector<Point> &points) {
        if (points.size() < 3)
            return points.size();

        int ret = 0;

        for (int i = 0; i < points.size(); ++i) {
            int sameCnt = 1;
            // double is not accurate enough for slope
            // unordered_map<double, int> slopeCnt;
            // use pair <int, int> (cannot pass compilation) to store slope
            // use string as key
            unordered_map<string, int> slopeCnt;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                    ++sameCnt;
                else if (points[i].x == points[j].x)
                    ++slopeCnt["Inf"];
                else {
                    // double sl = static_cast<double>(points[i].y -
                    // points[j].y) / (points[i].x - points[j].x);
                    int y0 = (points[i].y - points[j].y);
                    int x0 = (points[i].x - points[j].x);
                    int cd = gcd(x0, y0);
                    ++slopeCnt[to_string(y0 / cd) + '/' + to_string(x0 / cd)];
                }
            }
            for (auto &s : slopeCnt) {
                ret = max(ret, s.second + sameCnt);
            }
            ret = max(ret, sameCnt);
        }

        return ret;
    }
};