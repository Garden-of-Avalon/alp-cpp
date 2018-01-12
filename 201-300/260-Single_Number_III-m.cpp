//  Given an array of numbers nums, in which exactly two elements appear only
//  once and all the other elements appear exactly twice. Find the two elements
//  that appear only once.

// For example:

// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

// Note:

//     The order of the result is not important. So in the above example, [5, 3]
//     is also correct. Your algorithm should run in linear runtime complexity.
//     Could you implement it using only constant space complexity?

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating
// all test cases.

class Solution {
  public:
    vector<int> singleNumber(vector<int> &nums) {
        int xor_res = 0;
        for (auto &n : nums)
            xor_res ^= n;

        // example:
        // xor_res = 000...110
        // -xor_res = 111...010
        // bit_and result is 000...010
        int last_set_bit = xor_res & -xor_res;

        vector<int> ret(2, 0);
        for (auto &n : nums)
            if (n & last_set_bit)
                ret[0] ^= n;
            else
                ret[1] ^= n;

        return ret;
    }
};