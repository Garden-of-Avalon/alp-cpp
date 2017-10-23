// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it is able to trap after raining.
// For example,
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In
// this case, 6 units of rain water (blue section) are being trapped. Thanks
// Marcos for contributing this image!

// two pointers
class Solution {
  public:
    int trap(vector<int> &height) {
        if (height.empty())
            return 0;
        auto l = height.begin(), r = height.end() - 1;
        int lmax = 0, rmax = 0, ans = 0;
        while (l != r) {
            if (*l < *r) {
                if (*l < lmax)
                    ans += lmax - *l;
                else
                    lmax = *l;
                ++l;
            } else {
                if (*r < rmax)
                    ans += rmax - *r;
                else
                    rmax = *r;
                --r;
            }
        }
        return ans;
    }
};

// area, inspired by DP solution
// also O(n)
// class Solution {
//   public:
//     int trap(vector<int> &height) {
//         if (height.empty())
//             return 0;

//         int lmax = 0, rmax = 0, temparea = 0, sum = 0;
//         auto l = height.begin();
//         auto r = height.rbegin();
//         for (; l != height.end(); ++l, ++r) {
//             sum += *l;
//             if (lmax < *l)
//                 lmax = *l;
//             temparea += lmax;
//             if (rmax < *r)
//                 rmax = *r;
//             temparea += rmax;
//         }

//         // temparea == sum + ans + size * max
//         return temparea - height.size() * rmax - sum;
//     }
// };