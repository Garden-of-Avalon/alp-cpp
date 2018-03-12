//  Given N axis-aligned rectangles where N > 0, determine if they all together
//  form an exact cover of a rectangular region.

// Each rectangle is represented as a bottom-left point and a top-right point.
// For example, a unit square is represented as [1,1,2,2]. (coordinate of
// bottom-left point is (1, 1) and top-right point is (2, 2)).

// Example 1:

// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [3,2,4,4],
//   [1,3,2,4],
//   [2,3,3,4]
// ]

// Return true. All 5 rectangles together form an exact cover of a rectangular
// region.

// Example 2:

// rectangles = [
//   [1,1,2,3],
//   [1,3,2,4],
//   [3,1,4,2],
//   [3,2,4,4]
// ]

// Return false. Because there is a gap between the two rectangular regions.

// Example 3:

// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [1,3,2,4],
//   [3,2,4,4]
// ]

// Return false. Because there is a gap in the top center.

// Example 4:

// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [1,3,2,4],
//   [2,2,4,4]
// ]

// Return false. Because two of the rectangles overlap with each other.

class Solution {
  public:
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        vector<int> big{INT_MAX, INT_MAX, INT_MIN, INT_MIN};

        set<pair<int,int>> points;
        int area = 0;

        auto addpoint = [&](const pair<int, int> &p) {
            if (!points.insert(p).second)
                points.erase(p);
        };

        auto checkrec = [&](const vector<int> &r) {
            big[0] = min(r[0], big[0]);
            big[1] = min(r[1], big[1]);
            big[2] = max(r[2], big[2]);
            big[3] = max(r[3], big[3]);

            vector<pair<int, int>> pts = {
                {r[0], r[1]}, {r[2], r[3]}, {r[0], r[3]}, {r[2], r[1]}};

            for (auto &&p : pts)
                addpoint(p);
        };

        for (auto &&r : rectangles) {
            area += (r[2] - r[0]) * (r[3] - r[1]);
            checkrec(r);
        }

        if (area == (big[2] - big[0]) * (big[3] - big[1])) {
            checkrec(big);
            if (points.empty())
                return true;
        }

        return false;
    }
};

class Solution {
  public:
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        vector<int> big{INT_MAX, INT_MAX, INT_MIN, INT_MIN};

        unordered_set<string> points;
        // long long area = 0;
        int area = 0;

        auto addpoint = [&](const string &p) {
            if (!points.insert(p).second)
                points.erase(p);
        };

        auto checkrec = [&](const vector<int> &r) {
            big[0] = min(r[0], big[0]);
            big[1] = min(r[1], big[1]);
            big[2] = max(r[2], big[2]);
            big[3] = max(r[3], big[3]);

            vector<string> pts = {to_string(r[0]) + ',' + to_string(r[1]),
                                  to_string(r[2]) + ',' + to_string(r[3]),
                                  to_string(r[0]) + ',' + to_string(r[3]),
                                  to_string(r[2]) + ',' + to_string(r[1])};

            for (auto &&p : pts)
                addpoint(p);
        };

        for (auto &&r : rectangles) {
            area += (r[2] - r[0]) * (r[3] - r[1]);
            checkrec(r);
        }

        if (area == (big[2] - big[0]) * (big[3] - big[1])) {
            checkrec(big);
            if (points.empty())
                return true;
        }

        return false;
    }
};

// class Solution {
//     bool combine(vector<int> &r, vector<int> &target) {
//         for (auto &&n : r)
//             cout << n << ' ';
//         cout << '\n';
//         cout << 'x' << '\n';

//         for (auto &&n : target)
//             cout << n << ' ';
//         cout << '\n';
//         cout << '\n';

//         if (r[0] == target[0] && r[2] == target[2] && r[3] == target[1])
//             target[1] = r[1];
//         else if (r[1] == target[1] && r[3] == target[3] && r[2] == target[0])
//             target[0] = r[0];
//         else
//             return false; // fail combine

//         return true;
//     }

//   public:
//     bool isRectangleCover(vector<vector<int>> &rectangles) {
//         if (rectangles.size() == 1)
//             return true;

//         vector<vector<int> *> rs;
//         for (auto &r : rectangles) {
//             rs.push_back(&r);
//         }

//         while (rs.size() > 1) {
//             sort(rs.begin(), rs.end(), [](const auto &a, const auto &b) {
//                 return (*a)[0] == (*b)[0] && (*a)[2] == (*b)[2] &&
//                            (*a)[3] == (*b)[1] ||
//                        (*a)[1] == (*b)[1] && (*a)[3] == (*b)[3] &&
//                            (*a)[2] == (*b)[0];
//             });

//             vector<vector<int> *> temprs;
//             for (int i = 0; i < rs.size(); ++i) {
//                 if (!temprs.empty() && combine(*temprs.back(), *rs[i]))
//                     temprs.pop_back();

//                 temprs.push_back(rs[i]);
//             }

//             for (auto &&r : temprs) {
//                 for (auto &&n : *r)
//                     cout << n << ' ';
//                 cout << '\n';
//             }
//             cout << string(10, '=') << endl;

//             if (temprs.size() == rs.size())
//                 return false;

//             rs = std::move(temprs);
//         }

//         return true;
//     }
// };