// Given a string containing only digits, restore it by returning all possible
// valid IP address combinations.

// For example:
// Given "25525511135",

// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)
            return {};

        vector<string> ret;

        for (int i = 1; i < 4; ++i)
            for (int j = 1; j < 4; ++j)
                for (int k = 1; k < 4; ++k) {
                    int l = s.size() - i - j - k;
                    if (l > 0 && l < 4) {
                        if (i > 1 && s[0] == '0' ||
                            j > 1 && s[i] == '0' ||
                            k > 1 && s[i + j] == '0' ||
                            l > 1 && s[i + j + k] == '0')
                            continue;

                        int a = stoi(s.substr(0, i));
                        int b = stoi(s.substr(i, j));
                        int c = stoi(s.substr(i + j, k));
                        int d = stoi(s.substr(i + j + k));

                        if (a < 256 && b < 256 && c < 256 && d < 256)
                            ret.push_back(to_string(a) + '.' +
                                          to_string(b) + '.' +
                                          to_string(c) + '.' +
                                          to_string(d));
                    }
                }

        return ret;
    }
};