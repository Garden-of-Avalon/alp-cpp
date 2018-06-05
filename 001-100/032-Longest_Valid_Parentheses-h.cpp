// Given a string containing just the characters '(' and ')', find the length of
// the longest valid (well-formed) parentheses substring.

// Example 1:

// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
// Example 2:

// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

class Solution {
  public:
    int longestValidParentheses(string s) {
        int len = s.size(), ret = 0;
        // dp[i] is the length of the logest valid parentheses end at s[i]
        vector<int> dp(len);

        for (int i = 1; i < len; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                else if (dp[i - 1] > 0) {
                    int j = i - dp[i - 1] - 1;
                    if (j >= 0 && s[j] == '(')
                        dp[i] = dp[i - 1] + 2 + (j - 1 >= 0 ? dp[j - 1] : 0);
                }

                ret = max(ret, dp[i]);
            }
        }

        return ret;
    }
};

// TODO:
// stack
// two scans

// ref:
// https://leetcode.com/problems/longest-valid-parentheses/solution/