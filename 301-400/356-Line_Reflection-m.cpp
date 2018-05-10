// Given n points on a 2D plane, find if there is such a line parallel to y-axis
// that reflect the given points.

// Example 1:
// Given points = [[1,1],[-1,1]], return true.

// Example 2:
// Given points = [[1,1],[-1,-1]], return false.

// Follow up:
// Could you do better than O(n2)?

class Solution {
  public:
    bool isReflected(vector<pair<int, int>> &points) {
        if (points.size() < 2)
            return true;

        set<pair<int, int>> pts(points.begin(), points.end());

        long long line2x = (*pts.begin()).first + (*pts.rbegin()).first;

        for (auto &&p : pts)
            if (!pts.count(make_pair(line2x - p.first, p.second)))
                return false;

        return true;
    }
};

// 20 ms
class Solution {
  public:
    bool isReflected(vector<pair<int, int>> &points) {
        if (points.size() < 2)
            return true;

        // remove repeated
        set<pair<int, int>> pts(points.begin(), points.end());
        points = vector<pair<int, int>>(pts.begin(), pts.end());

        int sz = points.size(), mid = sz / 2;

        sort(points.begin() + mid, points.end(), [](auto &p1, auto &p2) {
            if (p1.first == p2.first)
                return p1.second > p2.second;
            return p1.first < p2.first;
        });

        // must be double
        double line2x = points[0].first + points[sz - 1].first,
               line = line2x / 2;

        for (int i = 0; i <= mid; ++i) {
            int j = sz - 1 - i;

            // bypass the points at the line
            if (points[i].first == line && points[j].first == line)
                continue;

            // check
            if (points[i].first + points[j].first != line2x ||
                points[i].second != points[j].second)
                return false;
        }

        return true;
    }
};