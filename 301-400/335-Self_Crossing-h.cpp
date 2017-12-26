//  You are given an array x of n positive numbers. You start at point (0,0) and
//  moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to
//  the south, x[3] metres to the east and so on. In other words, after each
//  move your direction changes counter-clockwise.

// Write a one-pass algorithm with O(1) extra space to determine, if your path
// crosses itself, or not.

// d can cross a, e can cross a, f can cross a. These are all possible cases.
// So, f can cross a, b, c; g can cross b, c, d...
//             b                              b
//    +----------------+             +----------------+
//    |                |             |                |
//    |                |             |                | a
//  c |                |           c |                |
//    |                | a           |                |    f
//    +----------->    |             |                | <----+
//             d       |             |                |      | e
//                     |             |                       |
//                                   +-----------------------+
//                                                d

class Solution {
  public:
    bool isSelfCrossing(vector<int> &x) {
        for (int i = 3; i < x.size(); ++i) {
            // d >= b, c <= a
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3])
                return true;
            // d == b, e + a >= c
            if (i > 3 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2])
                return true;
            // d >= b, f >= d - b, e >= c - a, e <= c
            if (i > 4 && x[i - 2] >= x[i - 4] && x[i] >= x[i - 2] - x[i - 4] &&
                x[i - 1] >= x[i - 3] - x[i - 5] && x[i - 1] <= x[i - 3])
                return true;
        }
        return false;
    }
};