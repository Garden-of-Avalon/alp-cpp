//  Divide two integers without using multiplication, division and mod operator.

// If it is overflow, return MAX_INT.

class Solution {
  public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;

        bool sign = (divisor ^ dividend) < 0 ? false : true;

        using ll = long long;

        ll dvd = labs(dividend);
        ll dvs = labs(divisor);

        int res = 0;
        while (dvd >= dvs) {
            ll temp = dvs;
            int i = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                i <<= 1;
            }
            dvd -= temp;
            res += i;
        }

        return sign ? res : -res;
    }
};
