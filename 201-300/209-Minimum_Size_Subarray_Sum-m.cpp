//  Given an array of n positive integers and a positive integer s, find the
//  minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
//  one, return 0 instead.

// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint.

// click to show more practice.
// More practice:

// If you have figured out the O(n) solution, try coding another solution of
// which the time complexity is O(n log n).

// Credits:
// Special thanks to @Freezen for adding this problem and creating all test
// cases

// O(n)
class Solution {
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int left = 0, sum = 0, ret = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= s) {
                ret = min(ret, i + 1 - left);
                sum -= nums[left++];
            }
        }

        return ret == INT_MAX ? 0 : ret;
    }
};

// O(nlogn)
class Solution {
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int ret = INT_MAX;
        vector<int> sums(nums.size() + 1);

        for (int i = 1; i <= nums.size(); ++i)
            sums[i] = sums[i - 1] + nums[i - 1];

        // no need to test sums[nums.size()] + s
        for (int i = 0; i < nums.size(); ++i) {
            // ? >= sums[i] + s, ? - sums[i] >= s
            auto notlessthan =
                lower_bound(sums.begin(), sums.end(), sums[i] + s);
            if (notlessthan != sums.end())
                ret =
                    min(ret, static_cast<int>(notlessthan - sums.begin()) - i);
        }

        return ret == INT_MAX ? 0 : ret;
    }
};

// a little different from ref. 325