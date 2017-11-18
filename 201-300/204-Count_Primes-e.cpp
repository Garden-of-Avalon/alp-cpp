// Description:
// Count the number of prime numbers less than a non-negative number, n.
// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test
// cases.

class Solution {
  public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;

        // 0-n-1, a[i] = i
        vector<bool> isprime(n, true);

        int cnt = 1; // 2
        for (int i = 3; i < n; i += 2)
            if (isprime[i]) {
                int temp = i << 1;
                while (temp < n) {
                    isprime[temp] = false;
                    temp += i;
                }
                ++cnt;
            }

        return cnt;
    }
};