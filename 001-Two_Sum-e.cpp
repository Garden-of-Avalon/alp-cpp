// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // Practice of iterator.
        // Actually, directly use 'int index' would be easier.
        for (auto iterBegin = nums.begin(); iterBegin != nums.end();
             ++iterBegin) {
            for (auto iterTemp = iterBegin + 1; iterTemp != nums.end();
                 ++iterTemp) {
                if (target == *iterBegin + *iterTemp)
                    return {std::distance(nums.begin(), iterBegin),
                            std::distance(nums.begin(), iterTemp)};
            }
        }
        return {-1, -1}; // self defined error message
    }
};