// Given a binary array, find the maximum number of consecutive 1s in this
// array.

// Example 1:
// Input: [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive
// 1s.
//     The maximum number of consecutive 1s is 3.
// Note:

// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000

class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int ret = 0, locMax = 0;

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == 1)
                ++locMax;
            else {
                ret = max(ret, locMax);
                locMax = 0;
                while (i + 1 < nums.size() && nums[i + 1] == 0)
                    ++i;
                // now i is last 0 or last element
            }

        ret = max(ret, locMax); // last update

        return ret;
    }
};

class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int ret = 0;
        auto r = find(nums.begin(), nums.end(), 1), l = r;

        while (r != nums.end()) {
            while (r != nums.end() && *l == *r)
                ++r;
            ret = max(ret, static_cast<int>(distance(l, r)));
            r = find(r, nums.end(), 1), l = r;
        }

        return ret;
    }
};