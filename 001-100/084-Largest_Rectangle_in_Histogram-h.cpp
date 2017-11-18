// Given n non-negative integers representing the histogram's bar height where
// the width of each bar is 1, find the area of largest rectangle in the
// histogram.
// Above is a histogram where width of each bar is 1, given height =
// [2,1,5,6,2,3].
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
// For example,
// Given heights = [2,1,5,6,2,3],
// return 10.

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        stack<int> indexes;
        int ret = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!indexes.empty() && heights[i] < heights[indexes.top()]) {
                int top = indexes.top();
                indexes.pop();
                ret = max(ret,
                          heights[top] *
                              (indexes.empty() ? i : i - indexes.top() - 1));
            }
            indexes.push(i);
        }
        return ret;
    }
};