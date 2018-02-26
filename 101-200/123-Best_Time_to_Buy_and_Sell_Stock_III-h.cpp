// Say you have an array for which the ith element is the price of a given stock
// on day i.

// Design an algorithm to find the maximum profit. You may complete at most two
// transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must
// sell the stock before you buy again).

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // after 1st buy, after 1st sold, after 2nd buy, after 2nd sold
        array<int, 4> mymoney{INT_MIN, 0, INT_MIN, 0};

        for (auto &&p : prices) {
            mymoney[3] = max(mymoney[3], mymoney[2] + p);
            mymoney[2] = max(mymoney[2], mymoney[1] - p);
            mymoney[1] = max(mymoney[1], mymoney[0] + p);
            mymoney[0] = max(mymoney[0], -p);

            // for (auto &&m : mymoney)
            //     cout << m << ' ';
            // cout << '\n';
        }

        return mymoney[3];
    }
};