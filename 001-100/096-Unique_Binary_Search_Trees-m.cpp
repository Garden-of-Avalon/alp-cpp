// Given n, how many structurally unique BST's (binary search trees) that store
// values 1...n?
// For example, Given n = 3, there are a total of 5 unique BST's.
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

class Solution {
  public:
    int numTrees(int n) {
        if (n < 1)
            return 1;

        vector<int> res(n + 1, 0);
        res[0] = res[1] = 1;

        for (int i = 2; i <= n; ++i)
            for (int j = 0; j < i; ++j)
                res[i] += res[j] * res[i - 1 - j];

        return res[n];
    }
};