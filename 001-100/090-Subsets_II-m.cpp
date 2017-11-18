// Given a collection of integers that might contain duplicates, nums, return
// all possible subsets.
// Note: The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,2], a solution is:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

// TODO
// Similar to 078
// use iterative way
class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        int sz = nums.size();
        vector<vector<int>> result(1, vector<int>());
        sort(nums.begin(), nums.end());

        int i, j, k, l, cnt;
        for (i = 0; i < sz;) {
            k = result.size();
            cnt = 0;
            while (cnt + i < sz && nums[cnt + i] == nums[i])
                ++cnt;
            for (j = 0; j < k; ++j) {
                for (l = 0; l < cnt; ++l) {
                    result.push_back(result[j]);
                    // instead push_back, we use insert here
                    result.back().insert(result.back().end(), l + 1, nums[i]);
                    // fill_n(back_inserter(result.back()), l + 1, nums[i]);
                }
            }
            i += cnt;
        }

        return result;
    }
};

// working for nums without duplicate
// class Solution {
//   public:
//     vector<vector<int>> subsetsWithDup(vector<int> &nums) {
//         int sz = nums.size();
//         vector<vector<int>> result(1, vector<int>());

//         int i, j, k;
//         for (int i = 0; i < sz; ++i) {
//             k = result.size();
//             for (int j = 0; j < k; ++j) {
//                 result.push_back(result[j]);
//                 result.back().push_back(nums[i]);
//             }
//         }

//         return result;
//     }
// };