//  Given two integers n and k, return all possible combinations of k numbers
//  out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

// backtracking taolu
class Solution {
  public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> curr;

        function<void(int, int)> backtrack = [&](int l, int r) {
            if (curr.size() == k)
                ret.push_back(curr);
            else
                for (int i = l; i <= r; ++i) {
                    curr.push_back(i);
                    backtrack(i + 1, r);
                    curr.pop_back();
                }
        };

        backtrack(1, n);
        return ret;
    }
};