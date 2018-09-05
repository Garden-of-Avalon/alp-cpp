// Given a set of N people (numbered 1, 2, ..., N), we would like to split
// everyone into two groups of any size.

// Each person may dislike some other people, and they should not go into the
// same group.

// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the
// people numbered a and b into the same group.

// Return true if and only if it is possible to split everyone into two groups
// in this way.

// Example 1:

// Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4], group2 [2,3]
// Example 2:

// Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Example 3:

// Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false

// Note:

// 1 <= N <= 2000
// 0 <= dislikes.length <= 10000
// 1 <= dislikes[i][j] <= N
// dislikes[i][0] < dislikes[i][1]
// There does not exist i != j for which dislikes[i] == dislikes[j].

// ref: 785
class Solution {
  public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        vector<int> group(N + 1);
        vector<unordered_set<int>> nbors(N + 1);

        for (auto &dis : dislikes) {
            nbors[dis[0]].insert(dis[1]);
            nbors[dis[1]].insert(dis[0]);
        }

        auto dfs = [&](auto &&self, int node, int g) {
            if (group[node] == -g)
                return false;
            if (group[node] == g)
                return true;

            group[node] = g;
            for (auto &nb : nbors[node])
                if (!self(self, nb, -g))
                    return false;

            return true;
        };

        for (int i = 1; i <= N; ++i)
            if (!group[i])
                if (!dfs(dfs, i, 1))
                    return false;

        return true;
    }
};