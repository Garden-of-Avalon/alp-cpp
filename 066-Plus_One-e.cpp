// Given a non-negative integer represented as a non-empty array of digits, plus
// one to the integer.
// You may assume the integer do not contain any leading zero, except the number
// 0 itself.
// The digits are stored such that the most significant digit is at the head of
// the list.

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        ++digits.back();
        for (auto riter = digits.rbegin(); riter != digits.rend() && *riter > 9;
             ++riter) {
            *riter = 0;
            if (riter + 1 != digits.rend()) {
                ++*(riter + 1);
            } else {
                // bad
                // digits.insert(digits.begin(), 1);
                // good
                digits[0] = 1;
                digits.push_back(0);
                break; // important, fuck!
            }
        }
        return digits;
    }
};