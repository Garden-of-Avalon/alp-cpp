// Given two strings S and T, return if they are equal when both are typed into
// empty text editors. # means a backspace character.

// Example 1:

// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:

// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:

// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:

// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:

// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
// Follow up:

// Can you solve it in O(N) time and O(1) space?

class Solution {
    string build(string &s) {
        string ret;

        for (auto &&c : s) {
            if (c == '#') {
                if (!ret.empty())
                    ret.pop_back();
            } else
                ret += c;
        }

        return ret;
    }

  public:
    bool backspaceCompare(string S, string T) { return build(S) == build(T); }
};

// O(n), O(1)
class Solution {
    int nextValidIndex(string &s, int i) {
        int bkcnt = 0;

        while (i >= 0) {
            if (s[i] == '#')
                ++bkcnt;
            else if (bkcnt)
                --bkcnt;
            else
                return i;

            --i;
        }

        return -1;
    }

  public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;

        while (i >= 0) {
            i  = nextValidIndex(S, i);
            j  = nextValidIndex(T, j);

            if (i == -1 || j == -1)
                return i == j;
            
            if (S[i--] != T[j--])
                return false;
        }

        return true;
    }
};