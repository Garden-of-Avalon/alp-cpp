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

    // in s.substr(0, valid_sz), cnt(par[0]) == cnt(par[1])
    void remove(const string &s, int valid_sz, int prev_j, const string &par) {
        for (int i = valid_sz, cnt = 0; i < s.size(); ++i) {
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

        // above can only handle the cases that we need remove some par[1]
        // so we need do it again reversely

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

// BFS
class Solution {
    bool isValid(const string &s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                ++cnt;
            else if (s[i] == ')')
                --cnt;

            if (cnt < 0)
                return false;
        }
        return cnt == 0;
    }

  public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;

        queue<string> q;
        q.push(s);

        bool foundValid = false;
        unordered_set<string> visited;

        while (!q.empty()) {
            auto s = q.front();
            q.pop();

            if (isValid(s)) {
                ret.push_back(s);
                foundValid = true;
            }

            if (!foundValid)
                for (int i = 0; i < s.size(); ++i)
                    if ((s[i] == '(' || s[i] == ')') &&
                        (i == 0 || s[i] != s[i - 1])) {
                        auto next_s = s.substr(0, i) + s.substr(i + 1);
                        if (visited.emplace(next_s).second)
                            q.push(next_s);
                    }
        }

        return ret;
    }
};