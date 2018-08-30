// A strobogrammatic number is a number that looks the same when rotated 180
// degrees (looked at upside down).

// Find all strobogrammatic numbers that are of length = n.

// Example:

// Input:  n = 2
// Output: ["11","69","88","96"]

class Solution {
  public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ret;
        vector<char> dict = {'0', '1', '6', '8', '9'};
        string curr;

        auto backtrack = [&](auto &&self, int need) -> void {
            if (need == 0)
                ret.push_back(curr);
            else
                for (auto &&c : dict) {
                    if (curr.empty() && c == '0')
                        continue;
                    curr.push_back(c);
                    self(self, need - 1);
                    curr.pop_back();
                }
        };

        backtrack(backtrack, n / 2);

        if (n % 2) {
            int sz = ret.size();
            ret.reserve(sz * 3);
            for (int i = 0; i < sz; ++i) {
                ret.push_back(ret[i] + '1');
                ret.push_back(ret[i] + '8');
                ret[i] += '0';
            }
        }

        for (auto &s : ret)
            for (int i = n / 2 - 1; i >= 0; --i)
                s += s[i] == '6' ? '9' : s[i] == '9' ? '6' : s[i];

        return ret;
    }
};