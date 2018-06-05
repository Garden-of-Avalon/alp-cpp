// Given a roman numeral, convert it to an integer.
// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
  public:
    int romanToInt(string s) {
        unordered_map<char, int> romanNumMap = {
            {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
            {'X', 10},   {'V', 5},   {'I', 1}};

        int ret = 0;
        for (int i = 0; i + 1 < s.size(); ++i)
            if (romanNumMap[s[i]] < romanNumMap[s[i + 1]])
                ret -= romanNumMap[s[i]];
            else
                ret += romanNumMap[s[i]];

        return ret + romanNumMap[s.back()]; // last one
    }
};