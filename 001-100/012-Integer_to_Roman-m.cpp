// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
  public:
    string intToRoman(int num) {
        vector<string> romans = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                 "XL", "X",  "IX", "V",  "IV", "I"};
        vector<int> numvalues = {1000, 900, 500, 400, 100, 90, 50,
                                 40,   10,  9,   5,   4,   1};
        string result;
        for (int i = 0; i < numvalues.size(); ++i)
            while (numvalues[i] <= num) {
                num -= numvalues[i];
                result += romans[i];
            }
        return result;
    }
};

// static mapping (Java)
// public static String intToRoman(int num) {
//     String M[] = {"", "M", "MM", "MMM"};
//     String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC",
//     "CM"};
//     String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX",
//     "XC"};
//     String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII",
//     "IX"};
//     return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
// }

// // roman to int ref
// class Solution {
//   public:
//     int romanToInt(string s) {
//         map<char, int> romanNumMap = {{'M', 1000}, {'D', 500}, {'C', 100},
//                                       {'L', 50},   {'X', 10},  {'V', 5},
//                                       {'I', 1}};
//         int result = 0, i = 0;
//         while (i < s.size() - 1) {
//             if (romanNumMap[s[i]] < romanNumMap[s[i + 1]])
//                 result -= romanNumMap[s[i++]];
//             else
//                 result += romanNumMap[s[i++]];
//         }
//         return result + romanNumMap[s[i]]; // last one
//     }
// };