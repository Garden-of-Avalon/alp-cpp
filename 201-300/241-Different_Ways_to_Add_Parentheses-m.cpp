// Given a string of numbers and operators, return all possible results from
// computing all the different possible ways to group numbers and operators. The
// valid operators are +, - and *.

// Example 1

// Input: "2-1-1".

// ((2-1)-1) = 0
// (2-(1-1)) = 2

// Output: [0, 2]

// Example 2

// Input: "2*3-4*5"

// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10

// Output: [-34, -14, -10, -10, 10]

class Solution {
  public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        for (int i = 0; i < input.size(); i++)
            if (ispunct(input[i]))
                for (auto &&x : diffWaysToCompute(input.substr(0, i)))
                    for (auto &&y : diffWaysToCompute(input.substr(i + 1)))
                        ret.push_back(input[i] == '+'
                                          ? x + y
                                          : input[i] == '-' ? x - y : x * y);
        return ret.empty() ? vector<int>{stoi(input)} : ret;
    }
};

// DP?
class Solution {
    unordered_map<string, vector<int>> dp;

  public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;

        for (int i = 0; i < input.size(); i++)
            if (ispunct(input[i])) {
                string subl = input.substr(0, i);
                string subr = input.substr(i + 1);
                auto &&retx = dp.find(subl) != dp.end()
                                  ? dp[subl]
                                  : diffWaysToCompute(subl);

                auto &&rety = dp.find(subr) != dp.end()
                                  ? dp[subr]
                                  : diffWaysToCompute(subr);

                for (auto &&x : retx)
                    for (auto &&y : rety)
                        ret.push_back(input[i] == '+'
                                          ? x + y
                                          : input[i] == '-' ? x - y : x * y);
            }

        if (ret.empty())
            ret.push_back(stoi(input));
        dp[input] = ret;
        return ret;
    }
};