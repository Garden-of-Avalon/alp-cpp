// Given two non-negative integers num1 and num2 represented as strings, return
// the product of num1 and num2.

// Note:

//     The length of both num1 and num2 is < 110.
//     Both num1 and num2 contains only digits 0-9.
//     Both num1 and num2 does not contain any leading zero.
//     You must not use any built-in BigInteger library or convert the inputs to
//     integer directly.

class Solution {
  public:
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size(), '0');

        for (int i = num1.size() - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                int prod = res[i + j + 1] - '0' +
                           (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = prod / 10;
                res[i + j + 1] = prod % 10 + '0';
            }
            // now res[i] is 0
            res[i] += carry;
        }

        auto not_zero_pos = res.find_first_not_of('0');
        if (not_zero_pos == string::npos)
            return "0";
        return res.substr(not_zero_pos);
    }
};