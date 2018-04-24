// Give a string s, count the number of non-empty (contiguous) substrings that
// have the same number of 0's and 1's, and all the 0's and all the 1's in these
// substrings are grouped consecutively.

// Substrings that occur multiple times are counted the number of times they
// occur.

// Example 1:
// Input: "00110011"
// Output: 6
// Explanation: There are 6 substrings that have equal number of consecutive 1's
// and 0's: "0011", "01", "1100", "10", "0011", and "01".

// Notice that some of these substrings repeat and are counted the number of
// times they occur.

// Also, "00110011" is not a valid substring because all the 0's (and 1's) are
// not grouped together. Example 2: Input: "10101" Output: 4 Explanation: There
// are 4 substrings: "10", "01", "10", "01" that have equal number of
// consecutive 1's and 0's. Note:

// s.length will be between 1 and 50,000.
// s will only consist of "0" or "1" characters.

// optimized
class Solution {
  public:
    int countBinarySubstrings(string s) {
        int ret = 0, prev_cnt = 0, cnt = 0;
        char curr = s[0]; // s.length will be between 1 and 50,000

        for (auto &&c : s) {
            if (c == curr)
                ++cnt;
            else {
                ret += min(cnt, prev_cnt);
                prev_cnt = cnt;
                cnt = 1;
                curr = c;
            }
        }

        return ret + min(cnt, prev_cnt); // last one
    }
};

class Solution {
  public:
    int countBinarySubstrings(string s) {
        vector<int> cnts;
        int cnt = 0;
        char curr = s[0]; // s.length will be between 1 and 50,000

        for (auto &&c : s) {
            if (c == curr)
                ++cnt;
            else {
                cnts.push_back(cnt);
                cnt = 1;
                curr = c;
            }
        }
        cnts.push_back(cnt); // last cnt

        int ret = 0;
        for (int i = 1; i < cnts.size(); ++i)
            ret += min(cnts[i], cnts[i - 1]);

        return ret;
    }
};

// TLE
class Solution {
  public:
    int countBinarySubstrings(string s) {
        vector<int> ret(s.size());

        for (int i = 1; i < s.size(); ++i) {
            int cnt = 1, j = i;
            while (j >= 0 && s[--j] == s[i])
                ++cnt;
            while (j >= 0 && cnt > 0 && s[j--] != s[i])
                --cnt;
            ret[i] = ret[i - 1] + (cnt == 0);
        }

        return ret.back();
    }
};