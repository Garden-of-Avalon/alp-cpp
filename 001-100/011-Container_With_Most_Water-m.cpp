// given n non-negative integers a1, a2, ..., an, where each represents a point
// at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
// of line i is at (i, ai) and (i, 0). find two lines, which together with
// x-axis forms a container, such that the container contains the most water.
// Note: You may not slant the container and n is at least 2.

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1, ret = 0;

        while (l < r) {
            ret = max(ret, min(height[l], height[r]) * (r - l));

            height[l] < height[r] ? ++l : --r;
        }

        return ret;
    }
};
