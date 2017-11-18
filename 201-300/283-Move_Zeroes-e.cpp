// Given an array nums, write a function to move all 0's to the end of it while
// maintaining the relative order of the non-zero elements.
// For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums
// should be [1, 3, 12, 0, 0].
// Note:
//     You must do this in-place without making a copy of the array.
//     Minimize the total number of operations.
// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating
// all test cases.

// similar to std remove
// http://www.cplusplus.com/reference/algorithm/remove/
// ref 027
// use iterator
class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        auto curriter = nums.begin(), enditer = nums.begin();
        for (; curriter != nums.end(); ++curriter)
            if (*curriter)
                std::swap(*curriter, *enditer++);
        // after loop, from enditer to nums.end() is 0
    }
};