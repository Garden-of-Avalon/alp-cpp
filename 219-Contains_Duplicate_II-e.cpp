// Given an array of integers and an integer k, find out whether there are two
// distinct indices i and j in the array such that nums[i] = nums[j] and the
// absolute difference between i and j is at most k.

class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        if (k > 0) {
            unordered_set<int> temp;
            for (int i = 0; i < nums.size(); ++i) {
                if (i > k)
                    temp.erase(nums[i - k - 1]);
                if (!temp.insert(nums[i]).second)
                    return true;
            }
        }
        return false;
    }
};