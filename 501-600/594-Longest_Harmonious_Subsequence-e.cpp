// We define a harmonious array is an array where the difference between its
// maximum value and its minimum value is exactly 1.

// Now, given an integer array, you need to find the length of its longest
// harmonious subsequence among all its possible subsequences.

// Example 1:
// Input: [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation: The longest harmonious subsequence is [3,2,2,2,3].
// Note: The length of the input array will not exceed 20,000.

class Solution {
  public:
    int findLHS(vector<int> &nums) {
        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        int ret = 0, small = nums[0], big = small + 1, cnt_s = 1, cnt_b = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == small)
                ++cnt_s;
            else if (nums[i] == big)
                ret = max(ret, cnt_s + (++cnt_b));
            else {
                if (nums[i] == big + 1) {
                    small = big;
                    ++big;
                    cnt_s = cnt_b;
                    cnt_b = 1;
                } else {
                    small = nums[i];
                    big = small + 1;
                    cnt_s = 1;
                    cnt_b = 0;
                }
            }
        }

        return ret;
    }
};

class Solution {
  public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> n_cnts;

        for (auto &&n : nums)
            ++n_cnts[n];

        int ret = 0;

        for (auto &&nc : n_cnts)
            if (n_cnts.find(nc.first + 1) != n_cnts.end())
                ret = max(ret, nc.second + n_cnts[nc.first + 1]);

        return ret;
    }
};

// method 3: by using hashmap, we can do it in just one loop (actually same with
// the above one)