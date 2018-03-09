// Say you have an array for which the ith element is the price of a given stock
// on day i.

// Design an algorithm to find the maximum profit. You may complete at most k
// transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must
// sell the stock before you buy again).

// Credits:
// Special thanks to @Freezen for adding this problem and creating all test
// cases.

class Solution {
    int maxProfit_122(vector<int> &prices) {
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i)
            ret += max(prices[i] - prices[i - 1], 0);
        return ret;
    }

  public:
    int maxProfit(int k, vector<int> &prices) {
        if (!k)
            return 0;

        if (k >= prices.size() / 2)
            return maxProfit_122(prices);

        vector<int> afterbuy(k, INT_MIN);
        vector<int> aftersell(k, 0);

        for (auto &&p : prices) {
            for (int i = k - 1; i > 0; --i) {
                aftersell[i] = max(afterbuy[i] + p, aftersell[i]);
                afterbuy[i] = max(aftersell[i - 1] - p, afterbuy[i]);
            }
            aftersell[0] = max(afterbuy[0] + p, aftersell[0]);
            afterbuy[0] = max(-p, afterbuy[0]);
        }

        return aftersell[k - 1];
    }
};

// write it to 2D dp, instead of 1D
class Solution {
    int maxProfit_122(vector<int> &prices) {
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i)
            ret += max(prices[i] - prices[i - 1], 0);
        return ret;
    }

  public:
    int maxProfit(int k, vector<int> &prices) {
        if (!k)
            return 0;

        if (k >= prices.size() / 2)
            return maxProfit_122(prices);

        vector<vector<int>> profit(k + 1, vector<int>(prices.size()));

        // profit[i][j] means after ith buy/sell, at the prices window 0-j
        // the value of max profit
        for (int i = 1; i <= k; ++i) {
            int after_buy = -prices[0];
            for (int j = 1; j < prices.size(); ++j) {
                // L: don't buy the previous; R: buy previous and sell today
                profit[i][j] = max(profit[i][j - 1], after_buy + prices[j]);
                // L: buy today's instad of previous; R: keep previous buy
                after_buy = max(profit[i - 1][j - 1] - prices[j], after_buy);
            }
        }

        return profit[k][prices.size() - 1];
    }
};