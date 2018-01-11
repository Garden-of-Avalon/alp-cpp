// Given an integer array of size n, find all elements that appear more than ⌊
// n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

// Boyer-Moore Majority Vote algorithm
class Solution {
  public:
    vector<int> majorityElement(vector<int> &nums) {
        if (nums.size() < 2)
            return nums;

        // just set candidate1 and candidate2 different
        int cnt1 = 0, cnt2 = 0, cdd1 = INT_MIN, cdd2 = INT_MAX;

        for (auto &n : nums) {
            if (n == cdd1)
                ++cnt1;
            else if (n == cdd2)
                ++cnt2;
            else if (cnt1 == 0) {
                cdd1 = n;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                cdd2 = n;
                cnt2 = 1;
            } else {
                --cnt1;
                --cnt2;
            }
        }

        vector<int> ret;

        if (count(nums.begin(), nums.end(), cdd1) > nums.size() / 3)
            ret.push_back(cdd1);
        if (count(nums.begin(), nums.end(), cdd2) > nums.size() / 3)
            ret.push_back(cdd2);

        return ret;
    }
};