// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity
// should be O(log (m+n)).
// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// The median is (2 + 3)/2 = 2.5

class Solution {
    // Following traditional naming
    // This function is to find k-th element in the merged array.
    // But we don't really do the merging process.
    double getkth(vector<int> &nums1, int index1, vector<int> &nums2,
                  int index2, int k) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        if (index1 > sz1 - 1)
            return nums2[index2 + k - 1];
        if (index2 > sz2 - 1)
            return nums1[index1 + k - 1];
        if (k == 1)
            return min(nums1[index1], nums2[index2]);

        int mid1 = INT_MAX, mid2 = INT_MAX;
        if (index1 + k / 2 - 1 < sz1)
            mid1 = nums1[index1 + k / 2 - 1];
        if (index2 + k / 2 - 1 < sz2)
            mid2 = nums2[index2 + k / 2 - 1];

        if (mid1 < mid2)
            return getkth(nums1, index1 + k / 2, nums2, index2, k - k / 2);
        else
            return getkth(nums1, index1, nums2, index2 + k / 2, k - k / 2);
    }

  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        int medL = (sz1 + sz2 + 1) / 2, medR = (sz1 + sz2 + 2) / 2;

        return (getkth(nums1, 0, nums2, 0, medL) +
                getkth(nums1, 0, nums2, 0, medR)) /
               2.0;
    }
};