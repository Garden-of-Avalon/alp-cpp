// Given a string that contains only digits 0-9 and a target value, return all
// possibilities to add binary operators (not unary) +, -, or * between the
// digits so they evaluate to the target value.

// Example 1:

// Input: num = "123", target = 6
// Output: ["1+2+3", "1*2*3"]
// Example 2:

// Input: num = "232", target = 8
// Output: ["2*3+2", "2+3*2"]
// Example 3:

// Input: num = "105", target = 5
// Output: ["1*0+5","10-5"]
// Example 4:

// Input: num = "00", target = 0
// Output: ["0+0", "0-0", "0*0"]
// Example 5:

// Input: num = "3456237490", target = 9191
// Output: []

class Solution {
  public:
    vector<string> addOperators(string num, int target) {
        if (num.empty())
            return {};

        vector<string> ret;
        using LL = long long int;

        auto backtrack = [&](auto &&self, string candStr, int st, LL preRes,
                             LL factor) {
            if (st == num.size() && preRes == target) {
                ret.push_back(candStr);
                return;
            }

            for (int i = st; i < num.size(); ++i) {
                if (i != st && num[st] == '0')
                    break;

                string currNumStr = num.substr(st, i + 1 - st);
                LL currNum = stoll(currNumStr);

                if (st == 0) {
                    self(self, candStr + currNumStr, i + 1, currNum, currNum);
                } else {
                    self(self, candStr + "+" + currNumStr, i + 1,
                         preRes + currNum, currNum);
                    self(self, candStr + "-" + currNumStr, i + 1,
                         preRes - currNum, -currNum);
                    self(self, candStr + "*" + currNumStr, i + 1,
                         preRes - factor + factor * currNum, factor * currNum);
                }
            }
        };

        backtrack(backtrack, "", 0, 0, 0);

        return ret;
    }
};