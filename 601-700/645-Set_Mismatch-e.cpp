// The set S originally contains numbers from 1 to n. But unfortunately, due to
// the data error, one of the numbers in the set got duplicated to another
// number in the set, which results in repetition of one number and loss of
// another number.

// Given an array nums representing the data status of this set after the error.
// Your task is to firstly find the number occurs twice and then find the number
// that is missing. Return them in the form of an array.

// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]
// Note:
// The given array size will in the range [2, 10000].
// The given array's numbers won't have any order.

class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> ret;

        unordered_set<int> ss;

        for (auto &&n : nums)
            if (!ss.insert(n).second)
                ret.push_back(n);

        for (int i = 1; i < nums.size() + 1; ++i)
            if (!ss.count(i)) {
                ret.push_back(i);
                break;
            }

        return ret;
    }
};

// good
class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> ret;

        for (auto &&n : nums)
            if (nums[abs(n) - 1] > 0)
                nums[abs(n) - 1] *= -1;
            else
                ret.push_back(abs(n));

        for (int i = 1; i <= nums.size(); ++i)
            if (nums[i - 1] > 0) {
                ret.push_back(i);
                break;
            }

        return ret;
    }
};

class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        int all_xor = 0, res0 = 0, res1 = 0;

        for (auto &&n : nums)
            all_xor ^= n;
        for (int i = 1; i <= nums.size(); i++)
            all_xor ^= i;
        // all_xor = duplicate ^ missing

        // example: 1100 & ~(1100 - 1) = 0100
        // use this one can divide the duplicate and missing
        int rightmostbit = all_xor & ~(all_xor - 1);

        for (auto &&n : nums)
            if (n & rightmostbit)
                res1 ^= n;
            else
                res0 ^= n;
        for (int i = 1; i <= nums.size(); ++i)
            if (i & rightmostbit)
                res1 ^= i;
            else
                res0 ^= i;

        // now one of res is missing and the other is duplicate
        // find it and duplicate at first
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == res0)
                return {res0, res1};

        return {res1, res0};
    }
};