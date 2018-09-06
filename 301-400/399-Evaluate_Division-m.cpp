// Equations are given in the format A / B = k, where A and B are variables
// represented as strings, and k is a real number (floating point number). Given
// some queries, return the answers. If the answer does not exist, return -1.0.

// Example:
// Given a / b = 2.0, b / c = 3.0.
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
// return [6.0, 0.5, -1.0, 1.0, -1.0 ].

// The input is: vector<pair<string, string>> equations, vector<double>& values,
// vector<pair<string, string>> queries , where equations.size() ==
// values.size(), and the values are positive. This represents the equations.
// Return vector<double>.

// According to the example above:

// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
// The input is always valid. You may assume that evaluating the queries will
// result in no division by zero and there is no contradiction.

class Solution {
  public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double> &values,
                                vector<pair<string, string>> queries) {
        // parent -> {child, value}, {child, value} ...
        // a / b = 2.0 => graph["a"] == {{"b", 2.0}}
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i].first].emplace(equations[i].second, values[i]);
            graph[equations[i].second].emplace(equations[i].first,
                                               1.0 / values[i]);
        }

        auto dfs = [&](auto &&self, string b, string e,
                       unordered_set<string> &visited) {
            if (graph.count(b)) {
                if (!visited.insert(b).second)
                    return -1.0;

                if (b == e)
                    return 1.0;

                if (graph[b].count(e))
                    return graph[b][e]; // value of b / e

                for (auto &child : graph[b]) {
                    double res = self(self, child.first, e, visited);
                    if (res != -1.0)
                        return child.second * res;
                }
            }
            return -1.0;
        };

        vector<double> ret(queries.size());
        for (int i = 0; i < ret.size(); ++i) {
            unordered_set<string> visited;
            ret[i] = dfs(dfs, queries[i].first, queries[i].second, visited);
        }

        return ret;
    }
};