// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?

class Solution {
  public:
    vector<int> getRow(int k) {
        vector<int> ret = {1};

        for (int i = 0; i < k; ++i)
            ret.push_back(static_cast<long long>(ret.back()) * (k - i) /
                          (i + 1));

        return ret;
    }
};

// method 2
class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1);
        ret[0] = 1;
        for (int i = 0; i <= rowIndex; ++i)
            for (int j = i; j > 0; --j)
                ret[j] += ret[j - 1];

        return ret;
    }
};

// method 3
// if all comb cannot be calculated as compile time, this method is not good
class Solution {
    using ull = unsigned long long;
    constexpr ull comb(ull n, ull k) {
        return k > 0 ? comb(n, k - 1) * (n + 1 - k) / k : 1;
    }

  public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;

        for (int i = 0; i <= rowIndex; ++i)
            ret.push_back(comb(rowIndex, i));

        return ret;
    }
};
