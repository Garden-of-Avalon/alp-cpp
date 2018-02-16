//  All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
//  T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
//  identify repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that
// occur more than once in a DNA molecule.

// For example,

// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].

class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        int n = s.size();
        for (int i = 0; i < n - 9; ++i)
            ++m[s.substr(i, 10)];

        vector<string> ret;
        for (auto &&s : m)
            if (s.second > 1)
                ret.push_back(s.first);

        return ret;
    }
};

// method 2: hash to integer