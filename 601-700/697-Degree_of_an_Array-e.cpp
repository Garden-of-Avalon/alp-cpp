// Given a non-empty array of non-negative integers nums, the degree of this
// array is defined as the maximum frequency of any one of its elements.

// Your task is to find the smallest possible length of a (contiguous) subarray
// of nums, that has the same degree as nums.

// Example 1:

// Input: [1, 2, 2, 3, 1]
// Output: 2
// Explanation:
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.

// Example 2:

// Input: [1,2,2,3,1,4,2]
// Output: 6

// Note:
// nums.length will be between 1 and 50,000.
// nums[i] will be an integer between 0 and 49,999.

class Solution {
  public:
    int findShortestSubArray(vector<int> &nums) {
        // In the array, [0]: count, [1]: lowest_index, [2]: highest_index
        unordered_map<int, array<int, 3>> info;

        for (int i = 0; i < nums.size(); ++i) {
            if (++info[nums[i]][0] == 1)
                info[nums[i]][1] = i;
            info[nums[i]][2] = i;
        }

        // frequency, value
        unordered_multimap<int, int> cnt_val;
        int maxcnt = 0;

        for (auto &&i : info) {
            cnt_val.emplace(i.second[0], i.first);
            maxcnt = max(maxcnt, i.second[0]);
        }

        int ret = INT_MAX;
        decltype(cnt_val.begin()) it;
        while ((it = cnt_val.find(maxcnt)) != cnt_val.end()) {
            ret = min(ret, info[it->second][2] - info[it->second][1]);
            cnt_val.erase(it);
        }
        return ret + 1;
    }
};

class Solution {
  public:
    int findShortestSubArray(vector<int> &nums) {
        // In the array, [0]: count, [1]: lowest_index, [2]: highest_index
        unordered_map<int, array<int, 3>> info;

        for (int i = 0; i < nums.size(); ++i) {
            if (++info[nums[i]][0] == 1)
                info[nums[i]][1] = i;
            info[nums[i]][2] = i;
        }

        int maxcnt = max_element(info.begin(), info.end(),
                                 [](auto &a, auto &b) {
                                     return a.second[0] < b.second[0];
                                 })
                         ->second[0];

        int ret = INT_MAX;
        for_each(info.begin(), info.end(), [&](auto &i) {
            if (i.second[0] == maxcnt)
                ret = min(ret, i.second[2] - i.second[1]);
        });

        return ret + 1;
    }
};