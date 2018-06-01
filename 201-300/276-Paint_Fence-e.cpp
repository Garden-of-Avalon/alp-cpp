// There is a fence with n posts, each post can be painted with one of the k
// colors.

// You have to paint all the posts such that no more than two adjacent fence
// posts have the same color.

// Return the total number of ways you can paint the fence.

// Note:
// n and k are non-negative integers.

// Example:

// Input: n = 3, k = 2
// Output: 6
// Explanation: Take c1 as color 1, c2 as color 2. All possible ways are:

//             post1  post2  post3
//  -----      -----  -----  -----
//    1         c1     c1     c2
//    2         c1     c2     c1
//    3         c1     c2     c2
//    4         c2     c1     c1
//    5         c2     c1     c2
//    6         c2     c2     c1

// again finite state machine
class Solution {
  public:
    int numWays(int n, int k) {
        if (!n)
            return 0;

        // state 1: post i is same as post i - 1
        // state 2: diffrent
        int s1 = 0, s2 = k;

        for (int i = 1; i < n; ++i) {
            swap(s1, s2);
            s2 = s1 * (k - 1) + s2 * (k - 1); // curr_s2, pre_s1
        }

        return s1 + s2;
    }
};