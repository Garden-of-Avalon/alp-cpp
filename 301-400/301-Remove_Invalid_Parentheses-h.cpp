// Remove the minimum number of invalid parentheses in order to make the input
// string valid. Return all possible results.

// Note: The input string may contain letters other than the parentheses ( and
// ).

// Example 1:

// Input: "()())()"
// Output: ["()()()", "(())()"]
// Example 2:

// Input: "(a)())()"
// Output: ["(a)()()", "(a())()"]
// Example 3:

// Input: ")("
// Output: [""]

// ref:
// https://leetcode.com/problems/remove-invalid-parentheses/discuss/75027/Easy-Short-Concise-and-Fast-Java-DFS-3-ms-solution
class Solution {
    vector<string> ret;

    void remove(const string &s, int prev_i, int prev_j, const string &par) {
        for (int i = prev_i, cnt = 0; i < s.size(); ++i) {
            if (s[i] == par[0])
                ++cnt;
            else if (s[i] == par[1])
                --cnt;

            if (cnt < 0) {
                for (int j = prev_j; j <= i; ++j)
                    if (s[j] == par[1] && (j == prev_j || s[j - 1] != par[1]))
                        remove(s.substr(0, j) + s.substr(j + 1), i, j, par);
                return;
            }
        }

        string rev_s(s.rbegin(), s.rend());

        if (par[0] == '(')
            remove(rev_s, 0, 0, ")(");
        else
            ret.push_back(rev_s);
    }

  public:
    vector<string> removeInvalidParentheses(string s) {
        remove(s, 0, 0, "()");
        return ret;
    }
};
