// Given a string S, we can transform every letter individually to be lowercase
// or uppercase to create another string.  Return a list of all possible strings
// we could create.

// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

// Input: S = "3z4"
// Output: ["3z4", "3Z4"]

// Input: S = "12345"
// Output: ["12345"]
// Note:

// S will be a string with length at most 12.
// S will consist only of letters or digits.

class Solution {
  public:
    vector<string> letterCasePermutation(string S) {
        vector<int> indices;
        for (int i = 0; i < S.size(); ++i)
            if (isalpha(S[i]))
                indices.push_back(i);

        int sz = pow(2, indices.size());
        for_each(S.begin(), S.end(), [](auto &c) { c = tolower(c); });
        vector<string> ret(sz, S);

        for (int i = 0; i < sz; ++i) {
            bitset<12> curr(i);
            for (int j = 0; j < 12; ++j)
                if (curr[j])
                    ret[i][indices[j]] = toupper(ret[i][indices[j]]);
        }

        return ret;
    }
};

// permutation (backtracking) TODO