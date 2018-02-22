//  Given a set of candidate numbers (C) (without duplicates) and a target
//  number (T), find all unique combinations in C where the candidate numbers
//  sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:

//     All numbers (including target) will be positive integers.
//     The solution set must not contain duplicate combinations.

// For example, given candidate set [2, 3, 6, 7] and target 7,
// A solution set is:

// [
//   [7],
//   [2, 2, 3]
// ]

class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> curr_comb; // current combination

        function<void(int, int)> backtrack = [&](int target, int start) {
            if (!target) {
                ret.push_back(curr_comb);
                return;
            }
            // key part of backtracking
            for (int i = start;
                 i != candidates.size() && target >= candidates[i]; ++i) {
                curr_comb.push_back(candidates[i]);
                backtrack(target - candidates[i], i);
                curr_comb.pop_back();
            }
        };

        backtrack(target, 0);

        return ret;
    }
};