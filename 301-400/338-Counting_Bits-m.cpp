// Given a non negative integer number num. For every numbers i in the range 0 ≤
// i ≤ num calculate the number of 1's in their binary representation and return
// them as an array.
// Example:
// For num = 5 you should return [0,1,1,2,1,2].
// Follow up:
//     It is very easy to come up with a solution with run time
//     O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in
//     a single pass?
//     Space complexity should be O(n).
//     Can you do it like a boss? Do it without using any builtin function like
//     __builtin_popcount in c++ or in any other language.
// Credits:
// Special thanks to @ syedee for adding this problem and creating all test
// cases.

// or refer to 191 O(1) function to calculate, total is O(n)
class Solution {
  public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            // example
            // 5, 6: 101 & 110 = 100, ret[6] = ret[4] + 1 = 2
            // 6, 7: 110 & 111 = 110, ret[7] = ret[6] + 1 = 3
            // 7, 8: 111 & 1000 = 1000, ret[8] = ret[8] + 1 = 1
            ret[i] = ret[i & (i - 1)] + 1;
        }
        return ret;
    }
};