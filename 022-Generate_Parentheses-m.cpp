// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
// For example, given n = 3, a solution set is:
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

class Solution {
    void stradd(vector<string> &v, string currstr, int l, int r) {
        if (!l && !r) {
            v.push_back(currstr);
            return;
        }
        // l: number of '(' left
        // r: number of ')' left
        if (l > 0)
            stradd(v, currstr + '(', l - 1, r + 1);
        // only after adding '(', i.e. r + 1,
        // we can do r - 1 and add ')'
        if (r > 0)
            stradd(v, currstr + ')', l, r - 1);
    }

  public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        stradd(ret, "", n, 0);
        return ret;
    }
};