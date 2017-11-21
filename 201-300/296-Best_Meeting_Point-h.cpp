// A group of two or more people wants to meet and minimize the total travel
// distance. You are given a 2D grid of values 0 or 1, where each 1 marks the
// home of someone in the group. The distance is calculated using Manhattan
// Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
// For example, given three people living at (0,0), (0,4), and (2,2):
// 1 - 0 - 0 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0
// The point (0,2) is an ideal meeting point, as the total travel distance of
// 2+2+2=6 is minimal. So return 6.

// N is the number of '1's
// 1. find meadian: O(mn) + 2O(N) // not practical working
// 2. sort way: O(mn) + 2O(NlogN) + O(N)
// 3. collect in sorted way: O(mn) + O(mn) + O(N)
// 3rd way would have high cache miss rate while iterating over column

class Solution {
  public:
    int minTotalDistance(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        // int sumI = 0, sumJ = 0;
        vector<int> Is, Js;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) {
                    // sumI += i;
                    // sumJ += j;
                    Is.push_back(i);
                    Js.push_back(j);
                }

        int pts = Is.size(); // points

        sort(Is.begin(), Is.end());
        sort(Js.begin(), Js.end());

        int ret = 0;
        for (int x = 0, y = pts - 1; x < y; ++x, --y)
            ret += Is[y] - Is[x] + Js[y] - Js[x];

        return ret;

        /** double, int or round(double) all won't work because it depends on
         * how many points are at the closest position of the mid point */
        // // std::round possible use
        // double midI = sumI * 1.0 / points, midJ = sumJ * 1.0 / points;
        // double ret = 0.0;
        // // int midI = sumI / points, midJ = sumJ / points;
        // // int ret = 0;
        // for (auto &i : Is)
        //     ret += abs(i - midI);
        // for (auto &j : Js)
        //     ret += abs(j - midJ);
    }
};
