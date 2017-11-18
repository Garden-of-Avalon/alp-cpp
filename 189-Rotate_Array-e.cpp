// Rotate an array of n elements to the right by k steps.
// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
// [5,6,7,1,2,3,4].
// Note:
// Try to come up as many solutions as you can, there are at least 3 different
// ways to solve this problem.
// [show hint]
// Hint:
// Could you do it in-place with O(1) extra space?
// Related problem: Reverse Words in a String II
// Credits:
// Special thanks to @Freezen for adding this problem and creating all test
// cases.

class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        int r = nums.size();

        if (!(k = k % r))
            return;

        int i = 0;
        while (k > 0 && i < r - k) {
            for (int j = r - k; j < r; ++j)
                swap(nums[i++], nums[j]);
            // if we have 5 elements left, and need to shift 11
            // actually we need to shift 1
            if (r - i < k)
                k = k % (r - i);
        } // loop until i == r - 1, or k == 0
    }
};

// easier way
class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        if (!(k = k % nums.size()))
            return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
    }
};