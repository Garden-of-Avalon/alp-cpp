// A binary watch has 4 LEDs on the top which represent the hours (0-11), and
// the 6 LEDs on the bottom represent the minutes (0-59).

// Each LED represents a zero or one, with the least significant bit on the
// right.

// For example, the above binary watch reads "3:25".

// Given a non-negative integer n which represents the number of LEDs that are
// currently on, return all possible times the watch could represent.

// Example:

// Input: n = 1
// Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08",
// "0:16", "0:32"]

// Note:

//     The order of output does not matter.
//     The hour must not contain a leading zero, for example "01:00" is not
//     valid, it should be "1:00". The minute must be consist of two digits and
//     may contain a leading zero, for example "10:2" is not valid, it should be
//     "10:02".

// ref 031
class Solution {
  public:
    vector<string> readBinaryWatch(int num) {
        const vector<int> h = {8, 4, 2, 1}, m = {32, 16, 8, 4, 2, 1};
        vector<bool> on(10);
        fill_n(on.rbegin(), num, true);

        auto convert = [&]() {
            int currh = 0, currm = 0;
            for (int i = 0; i < 4; ++i)
                if (on[i])
                    currh += h[i];
            for (int i = 0; i < 6; ++i)
                if (on[i + 4])
                    currm += m[i];

            if (currh > 11 || currm > 59)
                return string();

            return to_string(currh) + ':' + (currm < 10 ? "0" : "") +
                   to_string(currm);
        };

        vector<string> ret;

        do {
            string temp = convert();
            if (temp != "")
                ret.push_back(temp);
        } while (next_permutation(on.begin(), on.end()));

        return ret;
    }
};

// self implemented backtracking
class Solution {
  public:
    vector<string> readBinaryWatch(int num) {
        const vector<int> h = {1, 2, 4, 8}, m = {1, 2, 4, 8, 16, 32};
        pair<int, int> curr = make_pair(0, 0); // h, m
        vector<string> ret;

        auto backtrack = [&](auto &&self, int n, int st) {
            if (n == 0) {
                if (curr.first < 12 && curr.second < 60)
                    ret.push_back(to_string(curr.first) + ':' +
                                  (curr.second < 10 ? "0" : "") +
                                  to_string(curr.second));
                return;
            }
            for (int i = st; i < 10; ++i)
                if (i < 4) {
                    curr.first += h[i];
                    self(self, n - 1, i + 1);
                    curr.first -= h[i];
                } else {
                    curr.second += m[i - 4];
                    self(self, n - 1, i + 1);
                    curr.second -= m[i - 4];
                }
        };

        backtrack(backtrack, num, 0);

        return ret;
    }
};

// other idea
// test every possible h and m to see if bits can matuch num