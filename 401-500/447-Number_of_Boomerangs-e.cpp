// Given n points in the plane that are all pairwise distinct, a "boomerang" is
// a tuple of points (i, j, k) such that the distance between i and j equals the
// distance between i and k (the order of the tuple matters).

// Find the number of boomerangs. You may assume that n will be at most 500 and
// coordinates of points are all in the range [-10000, 10000] (inclusive).

// Example:
// Input:
// [[0,0],[1,0],[2,0]]

// Output:
// 2

// Explanation:
// The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

class Solution {
  public:
    int numberOfBoomerangs(vector<pair<int, int>> &points) {
        int ret = 0;
        for (auto &&pi : points) {
            unordered_map<double, int> dist(points.size());
            for (auto &&pj : points)
                ++dist[hypot(pi.first - pj.first, pi.second - pj.second)];
            for (auto &&d : dist)
                ret += d.second * (d.second - 1);
        }
        return ret;
    }
};

class Solution {
  public:
    int numberOfBoomerangs(vector<pair<int, int>> &points) {
        int ret = 0;
        for (auto &&pi : points) {
            unordered_map<double, int> dist(points.size());
            for (auto &&pj : points)
                ret +=
                    2 *
                    dist[hypot(pi.first - pj.first, pi.second - pj.second)]++;
        }
        return ret;
    }
};