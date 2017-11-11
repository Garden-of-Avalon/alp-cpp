// Find the total area covered by two rectilinear rectangles in a 2D plane.
// Each rectangle is defined by its bottom left corner and top right corner as
// shown in the figure. Rectangle Area
// Assume that the total area is never beyond the maximum possible value of int.
// Credits:
// Special thanks to @mithmatt for adding this problem, creating the above image
// and all test cases.

class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C - A) * (D - B);
        int s2 = (G - E) * (H - F);
        int r = s1 + s2;
        // 2 is at left, right, down, up of 1
        if (G <= A || E >= C || H <= B || F >= D)
            return r;

        vector<int> xs = {A, C, E, G};
        vector<int> ys = {B, D, F, H};
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        return r - (xs[2] - xs[1]) * (ys[2] - ys[1]);
    }
};


// Java ref
// int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

//     int areaOfSqrA = (C - A) * (D - B);
//     int areaOfSqrB = (G - E) * (H - F);

//     int left = Math.max(A, E);
//     int right = Math.min(G, C);
//     int bottom = Math.max(F, B);
//     int top = Math.min(D, H);

//     // If overlap
//     int overlap = 0;
//     if (right > left && top > bottom)
//         overlap = (right - left) * (top - bottom);

//     return areaOfSqrA + areaOfSqrB - overlap;
// }