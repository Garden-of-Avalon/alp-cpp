// Validate if a given string is numeric.

// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true

// Note: It is intended for the problem statement to be ambiguous. You should
// gather all requirements up front before implementing one.

class Solution {
  public:
    bool isNumber(string s) {
        regex pattern(
            "(\\s+)?[+-]?((\\d+\\.?(\\d+)?)|(\\.\\d+))(e[+-]?\\d+)?(\\s+)?");

        return regex_match(s, pattern);
    }
};

// SHIT question
// ref test cases
// test(1, "123", true);
// test(2, " 123 ", true);
// test(3, "0", true);
// test(4, "0123", true); // ???
// test(5, "00", true);  // ???
// test(6, "-10", true);
// test(7, "-0", true);
// test(8, "123.5", true);
// test(9, "123.000000", true);
// test(10, "-500.777", true);
// test(11, "0.0000001", true);
// test(12, "0.00000", true);
// test(13, "0.", true);  
// test(14, "00.5", true); // ????
// test(15, "123e1", true);
// test(16, "1.23e10", true);
// test(17, "0.5e-10", true);
// test(18, "1.0e4.5", false);
// test(19, "0.5e04", true);
// test(20, "12 3", false);
// test(21, "1a3", false);
// test(22, "", false);
// test(23, "     ", false);
// test(24, null, false);
// test(25, ".1", true);
// test(26, ".", false);
// test(27, "2e0", true); 
// test(28, "+.8", true);  
// test(29, " 005047e+6", true);  // ????????????