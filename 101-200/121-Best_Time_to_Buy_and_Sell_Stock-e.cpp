// Say you have an array for which the ith element is the price of a given stock
// on day i.
// If you were only permitted to complete at most one transaction (ie, buy one
// and sell one share of the stock), design an algorithm to find the maximum
// profit.
// Example 1:
// Input: [7, 1, 5, 3, 6, 4]
// Output: 5
// max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger
// than buying price)
// Example 2:
// Input: [7, 6, 4, 3, 1]
// Output: 0
// In this case, no transaction is done, i.e. max profit = 0.

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int minbuy = INT_MAX, profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            minbuy = prices[i] < minbuy ? prices[i] : minbuy;
            profit =
                (prices[i] - minbuy) > profit ? prices[i] - minbuy : profit;
        }
        return profit;
    }
};

// rewrite ref 123
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // after 1st buy, after 1st sell
        array<int, 2> mymoney{INT_MIN, 0};
        for(auto &&p :prices) {
            mymoney[1] = max(mymoney[1], mymoney[0] + p);
            mymoney[0] = max(mymoney[0], -p);
        }

        return mymoney[1];
    }
};
