// Given an integer n, count the total number of digit 1 appearing in all
// non-negative integers less than or equal to n.
// For example:
// Given n = 13,
// Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12,
// 13.

class Solution {
  public:
    int countDigitOne(int n) {
        if (n < 0)
            return 0;

        vector<int> steps;
        for (int i = 1; i <= n; i *= 10) {
            steps.push_back(i);
            if (INT_MAX / i < 10)
                break;
        }

        int cnt = 0;

        for (auto riter = steps.rbegin(); riter != steps.rend(); ++riter) {
            // at each loop, add contribution of this digit
            // e.g. for 1124
            // 1st loop, we add 125 for 1000 digit contribution
            // 2nd loop, we add 25 + 100 (100-199) for 100 digit contribution
            // 3rd loop, we add 10 + 10 * (n/100) (010-019, 110-119...1010-1019)
            // 4th loop, we add 1 + 1 * (n/10) (0001, 0011, 0021...1111)
            int digit = (n / *riter) % 10;
            if (digit == 1)
                cnt += n % *riter + 1;
            else if (digit > 1)
                cnt += *riter;
            cnt += *riter * (n / *riter / 10);
        }

        return cnt;
    }
};