// given n non-negative integers a1, a2, ..., an, where each represents a point
// at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
// of line i is at (i, ai) and (i, 0). find two lines, which together with
// x-axis forms a container, such that the container contains the most water.
// Note: You may not slant the container and n is at least 2.

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int area = 0;
        int index1 = 0, index2 = height.size() - 1;
        while (index1 < index2) {
            area = max(area,
                       min(height[index1], height[index2]) * (index2 - index1));
            height[index1] < height[index2] ? ++index1 : --index2;
        }
        return area;
    }
};

// Bad version
// class Solution {
//   public:
//     int maxArea(vector<int> &height) {
//         int area = 0;
//         int index1, index2, sz = height.size();
//         for (index1 = 0; index1 < sz; ++index1)
//             for (index2 = index1 + 1; index2 < sz; ++index2)
//                 area = max(area,
//                            min(height[index1], height[index2]) *
//                                (index2 - index1));
//         return area;
//     }
// };