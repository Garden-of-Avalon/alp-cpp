// Determine whether an integer is a palindrome. Do this without extra space.

class Solution {
  public:
    bool isPalindrome(int x) {
        // x < 0, or 10, 100, 2020, etc.
        if (x < 0 || (x > 9 && x % 10 == 0))
            return false;
        // this cost is necessary
        int result = 0;
        while (x >= result) {
            (result *= 10) += (x % 10);
            // 12021, or 120021
            if (x == result || (x /= 10) == result)
                return true;
        }
        return false;
    }
};