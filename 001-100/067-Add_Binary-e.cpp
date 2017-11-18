// Given two binary strings, return their sum (also a binary string).
// For example,
// a = "11"
// b = "1"
// Return "100".

class Solution {
  public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            return addBinary(b, a);
        // a is longer than or same length as b
        char carry = '0';
        int i, j;
        for (i = a.size() - 1, j = b.size() - 1; j > -1; --i, --j) {
            if (a[i] == '1' && b[j] == '1') {
                a[i] = carry;
                carry = '1';
            } else if (a[i] == '1' || b[j] == '1')
                a[i] = carry == '0' ? '1' : '0';
            else {
                a[i] = carry;
                carry = '0';
            }
        }
        while (carry == '1' && i > -1) {
            if (a[i] == '0') {
                a[i] = carry;
                carry = '0';
            } else
                a[i] = '0';
            --i;
        }
        return carry == '0' ? a : '1' + a;
    }
};

// other solution: change to int/long int;
