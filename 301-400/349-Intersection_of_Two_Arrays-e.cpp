//  Given two arrays, write a function to compute their intersection.
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
// Note:
//     Each element in the result must be unique.
//     The result can be in any order.

class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end()), n;
        for (auto &x : nums2)
            if (m.find(x) != m.end())
                n.insert(x);
        return vector<int>(n.begin(), n.end());
    }
};