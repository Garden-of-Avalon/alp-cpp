//  Given an unsorted array of integers, find the length of the longest
//  consecutive elements sequence.
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its
// length: 4.
// Your algorithm should run in O(n) complexity.

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int ret = 0;
        for (auto n : nums)
            if (numset.find(n - 1) == numset.end()) {
                int currlen = 1;
                while (numset.find(++n) != numset.end()) {
                    ++currlen;
                    numset.erase(n); // increase performance of numset
                }
                ret = max(currlen, ret);
            }
        return ret;
    }
};