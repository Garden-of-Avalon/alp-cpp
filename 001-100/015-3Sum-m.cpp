// Given an array S of n integers, are there elements a, b, c in S such that a +
// b + c = 0? Find all unique triplets in the array which gives the sum of zero.
// Note: The solution set must not contain duplicate triplets.
// For example, given array S = [-1, 0, 1, 2, -1, -4],
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end()); // nlog(n)
        vector<vector<int>> result;
        int sz = nums.size();
        // O(n^2)
        for (int i = 0; i < sz - 2; ++i) {
            int j = i + 1, k = sz - 1;
            while (j < k) {
                if (nums[j] + nums[k] < -nums[i])
                    ++j;
                else if (nums[j] + nums[k] > -nums[i])
                    --k;
                else {
                    // acutally i, j, k; just combine j++ and k-- here.
                    result.push_back({nums[i], nums[j++], nums[k--]});
                    // bypassing same elements (j, k)
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                }
            }
            // bypassing same elements (i)
            while (i < sz - 1 && nums[i + 1] == nums[i])
                ++i;
        }
        return result;
    }
};