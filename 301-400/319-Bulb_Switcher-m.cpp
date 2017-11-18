// There are n bulbs that are initially off. You first turn on all the bulbs.
// Then, you turn off every second bulb. On the third round, you toggle every
// third bulb (turning on if it's off or turning off if it's on). For the ith
// round, you toggle every i bulb. For the nth round, you only toggle the last
// bulb. Find how many bulbs are on after n rounds.
// Example:
// Given n = 3.
// At first, the three bulbs are [off, off, off].
// After first round, the three bulbs are [on, on, on].
// After second round, the three bulbs are [on, off, on].
// After third round, the three bulbs are [on, off, off].
// So you should return 1, because there is only one bulb is on.

// only 1^2, 2^2, 3^2 ... will be on
// because these bulb will be switched odd times.
// example:
// 4 is switched at 1, 2, 4
// 6 is switched at 1, 2, 3, 6
class Solution {
  public:
    int bulbSwitch(int n) { return sqrt(n); }
};

// TLE
class Solution {
  public:
    int bulbSwitch(int n) {
        if (n < 2)
            return n;
        vector<bool> status(n, true);
        for (int i = 2; i <= n; ++i) {
            for (int j = i - 1; j < n; j += i) {
                status[j] = !status[j];
            }
        }

        int cnt = 0;
        for (auto &&s : status) {
            if (s)
                ++cnt;
        }

        return cnt;
    }
};