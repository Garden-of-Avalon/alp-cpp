// Given an undirected graph, return true if and only if it is bipartite.

// Recall that a graph is bipartite if we can split it's set of nodes into two
// independent subsets A and B such that every edge in the graph has one node in
// A and another node in B.

// The graph is given in the following form: graph[i] is a list of indexes j for
// which the edge between nodes i and j exists.  Each node is an integer between
// 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i]
// does not contain i, and it doesn't contain any element twice.

// Example 1:
// Input: [[1,3], [0,2], [1,3], [0,2]]
// Output: true
// Explanation:
// The graph looks like this:
// 0----1
// |    |
// |    |
// 3----2
// We can divide the vertices into two groups: {0, 2} and {1, 3}.
// Example 2:
// Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
// Output: false
// Explanation:
// The graph looks like this:
// 0----1
// | \  |
// |  \ |
// 3----2
// We cannot find a way to divide the set of nodes into two independent subsets.

// Note:

// graph will have length in range [1, 100].
// graph[i] will contain integers in range [0, graph.length - 1].
// graph[i] will not contain i or duplicate values.
// The graph is undirected: if any element j is in graph[i], then i will be in
// graph[j].

class Solution {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        vector<unordered_set<int>> groups(2);

        auto dfs = [&](auto &&self, int node, int gi) {
            auto nextgi = gi ^ 1;
            if (groups[nextgi].count(node))
                return false;

            if (!groups[gi].insert(node).second)
                return true; // already processed gi and its nbors

            for (auto &nbor : graph[node])
                if (!self(self, nbor, nextgi))
                    return false;

            return true;
        };

        for (int i = 0; i < graph.size(); ++i)
            if (graph[i].size() && !groups[0].count(i) && !groups[1].count(i))
                if (!dfs(dfs, i, 0))
                    return false;

        return true;
    }
};