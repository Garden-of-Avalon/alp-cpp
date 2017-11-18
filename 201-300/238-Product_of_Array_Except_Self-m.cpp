// Given an array of n integers where n > 1, nums, return an array output such
// that output[i] is equal to the product of all the elements of nums except
// nums[i].
// Solve it without division and in O(n).
// For example, given [1,2,3,4], return [24,12,8,6].
// Follow up:
// Could you solve it with constant space complexity? (Note: The output array
// does not count as extra space for the purpose of space complexity analysis.)

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> output(nums.size(), 1);
        int left = 1, right = 1, i, j;
        for (i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j) {
            output[i] *= left;
            left *= nums[i];
            output[j] *= right;
            right *= nums[j];
        }
        return output;
    }
};