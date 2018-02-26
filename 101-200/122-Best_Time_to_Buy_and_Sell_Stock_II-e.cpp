// Say you have an array for which the ith element is the price of a given stock
// on day i.
// Design an algorithm to find the maximum profit. You may complete as many
// transactions as you like (ie, buy one and sell one share of the stock
// multiple times). However, you may not engage in multiple transactions at the
// same time (ie, you must sell the stock before you buy again).

// better
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};

// class Solution {
//   public:
//     int maxProfit(vector<int> &prices) {
//         int sz = prices.size();
//         if (sz < 2)
//             return 0;
//         int minbuyindex, i = 0, profit = 0;
//         while (i < sz - 1) {
//             while (i + 1 < sz && prices[i] >= prices[i + 1])
//                 ++i;
//             cout << i << endl;
//             minbuyindex = i;
//             while (i + 1 < sz && prices[i] <= prices[i + 1])
//                 ++i;
//             profit += (prices[i] - prices[minbuyindex]);
//         }
//         return profit;
//     }
// };

// Do it again
// class Solution {
//   public:
//     int maxProfit(vector<int> &prices) {
//         int profit = 0;
//         int i = 0;
//         while (i < prices.size()) {
//             while (i + 1 < prices.size() && prices[i] >= prices[i + 1])
//                 ++i;
//             int buyin = prices[i];
//             while (i + 1 < prices.size() && prices[i] < prices[i + 1])
//                 ++i;
//             profit += prices[i] - buyin;
//             ++i;
//         }
//         return profit;
//     }
// };

// note: this is not suitable for the dp method (123)