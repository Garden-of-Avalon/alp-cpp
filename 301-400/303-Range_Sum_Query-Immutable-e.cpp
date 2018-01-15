// Given an integer array nums, find the sum of the elements between indices i
// and j (i ≤ j), inclusive.

// Example:

// Given nums = [-2, 0, 3, -5, 2, -1]

// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3

// Note:

//     You may assume that the array does not change.
//     There are many calls to sumRange function.

class NumArray {
    vector<int> cumulate_sum;

  public:
    NumArray(vector<int> nums) : cumulate_sum(nums) {
        for (int i = 1; i < cumulate_sum.size(); ++i)
            cumulate_sum[i] += cumulate_sum[i - 1];
    }

    int sumRange(int i, int j) {
        return i == 0 ? cumulate_sum[j] : cumulate_sum[j] - cumulate_sum[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

// looks like faster, but actually not so.
// note: may need to check j
class NumArray {
    vector<int> cumulate_sum = {0};

  public:
    NumArray(vector<int> nums) {
        for (auto &n : nums)
            cumulate_sum.push_back(cumulate_sum.back() + n);
    }

    int sumRange(int i, int j) { return cumulate_sum[j + 1] - cumulate_sum[i]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */