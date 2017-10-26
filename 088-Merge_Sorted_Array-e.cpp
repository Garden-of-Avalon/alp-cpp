// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
// one sorted array.
// Note:
// You may assume that nums1 has enough space (size that is greater or equal to
// m + n) to hold additional elements from nums2. The number of elements
// initialized in nums1 and nums2 are m and n respectively.

// From the end
class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int k = m + n - 1;
        --m;
        --n;
        while (n >= 0) {
            if (m == -1 || nums2[n] > nums1[m])
                nums1[k--] = nums2[n--];
            else
                nums1[k--] = nums1[m--];
        }
    }
};

// some error
// class Solution {
//   public:
//     void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
//         // i for nums1, j for nums2, k for m+n
//         int i = 0, j = 0;
//         while (i < m && j < n) {
//             if (nums1[i] > nums2[j]) {
//                 int temp = nums1[i];
//                 swap(nums1[i], nums2[j]);
//                 while (++i < m && ++j < n && temp > nums2[j]) {
//                     swap(nums1[i], nums2[j]);
//                 }
//             }
//             if (i < m)
//                 ++i;
//             if (j < n)
//                 ++j;
//         }
//         std::copy(nums2.begin(), nums2.end(), nums1.begin() + i);
//     }
// };