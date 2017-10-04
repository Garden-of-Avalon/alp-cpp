// Given a string s and a non-empty string p, find all the start indices of p's
// anagrams in s.
// Strings consists of lowercase English letters only and the length of both
// strings s and p will not be larger than 20,100.
// The order of output does not matter.
// Example 1:
// Input:
// s: "cbaebabacd" p: "abc"
// Output:
// [0, 6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:
// Input:
// s: "abab" p: "ab"
// Output:
// [0, 1, 2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.size() > s.size())
            return result;

        map<char, int> pmap;
        for (auto &c : p)
            ++pmap[c];

        int i = 0, j = 0, mapsz = pmap.size();

        while (j < s.size()) {
            if (pmap.find(s[j]) != pmap.end()) {
                --pmap[s[j]];
                if (!pmap[s[j]])
                    --mapsz;
            }
            ++j;

            while (!mapsz) {
                if (pmap.find(s[i]) != pmap.end()) {
                    ++pmap[s[i]];
                    if (pmap[s[i]] > 0)
                        ++mapsz;
                }

                if (j - i == p.size())
                    result.push_back(i);

                ++i;
            }
        }

        return result;
    }
};