// Given a positive integer, return its corresponding column title as appear in
// an Excel sheet.
// For example:
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB
// Credits:
// Special thanks to @ifanchu for adding this problem and creating all test
// cases.

class Solution {
  public:
    string convertToTitle(int n) {
        string ret;
        char tailletter;
        while (n) {
            tailletter = 'A' + (n - 1) % 26;
            ret = tailletter + ret;
            n = (n - 1) / 26;
        }
        return ret;
    }
};