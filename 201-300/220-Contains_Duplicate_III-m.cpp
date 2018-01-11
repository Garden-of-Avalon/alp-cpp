// Given an array of integers, find out whether there are two distinct indices i
// and j in the array such that the absolute difference between nums[i] and
// nums[j] is at most t and the absolute difference between i and j is at most
// k.

// self balanced BST
class Solution {
  public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (!k) // distinct i, j
            return false;

        set<long long> numset; // fucking overflow!

        for (int i = 0; i < nums.size(); ++i) {
            auto it = numset.lower_bound(nums[i]);
            if (it != numset.end() && *it - nums[i] <= t ||
                it != numset.begin() && nums[i] - *(--it) <= t)
                return true;

            numset.insert(nums[i]);
            if (numset.size() > k)
                numset.erase(nums[i - k]);
        }

        return false;
    }
};

// bucket sort, TODO