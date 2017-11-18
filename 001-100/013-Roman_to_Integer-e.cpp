// Given a roman numeral, convert it to an integer.
// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
  public:
    int romanToInt(string s) {
        map<char, int> romanNumMap = {{'M', 1000}, {'D', 500}, {'C', 100},
                                      {'L', 50},   {'X', 10},  {'V', 5},
                                      {'I', 1}};
        int result = 0, i = 0;
        while (i < s.size() - 1) {
            if (romanNumMap[s[i]] < romanNumMap[s[i + 1]])
                result -= romanNumMap[s[i++]];
            else
                result += romanNumMap[s[i++]];
        }
        return result + romanNumMap[s[i]]; // last one
    }
};