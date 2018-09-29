// Given an integer array, your task is to find all the different possible
// increasing subsequences of the given array, and the length of an increasing
// subsequence should be at least 2 .

// Example:
// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
// [4,7,7]]

// Note:
// The length of the given array will not exceed 15.
// The range of integer in the given array is [-100,100].
// The given array may contain duplicates, and two equal integers should also be
// considered as a special case of increasing sequence.

class Solution {
  public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        set<vector<int>> ret;
        vector<int> curr;

        auto backtrack = [&](auto &&self, vector<int>::iterator it) {
            if (it == nums.end()) {
                if (curr.size() > 1)
                    ret.emplace(curr);
                return;
            }

            if (curr.empty() || curr.back() <= *it) {
                curr.push_back(*it);
                self(self, it + 1);
                curr.pop_back();
            }

            // already treated same num above, bypass them here
            while (it + 1 != nums.end() && *(it + 1) == *it)
                ++it;
            self(self, it + 1);
        };

        backtrack(backtrack, nums.begin());

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};

class Solution {
  public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        vector<vector<int>> ret;
        vector<int> curr;

        auto backtrack = [&](auto &&self, vector<int>::iterator st) -> void {
            if (curr.size() > 1)
                ret.push_back(curr);

            // for each recursion, only visit a specific num once
            // to make sure no duplicates in ret
            unordered_set<int> visited;

            for (auto it = st; it != nums.end(); ++it)
                if ((curr.empty() || curr.back() <= *it) &&
                    !visited.count(*it)) {
                    curr.push_back(*it);
                    self(self, it + 1);
                    curr.pop_back();

                    visited.emplace(*it);
                }
        };

        backtrack(backtrack, nums.begin());

        return ret;
    }
};