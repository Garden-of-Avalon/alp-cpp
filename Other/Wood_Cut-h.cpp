// Given n pieces of wood with length L[i] (integer array). Cut them into small
// pieces to guarantee you could have equal or more than k pieces with the same
// length. What is the longest length you can get from the n pieces of wood?
// Given L & k, return the maximum length of the small pieces. Notice

// You couldn't cut wood into float length.

// If you couldn't get >= k pieces, return 0.

class Solution {
    int getnum(vector<int> &L, const int &len) {
        return accumulate(
            L.begin(), L.end(), 0,
            [&](const int &l, const int &r) { return l + r / len; });
    }

  public:
    /*
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        if (L.empty())
            return 0;

        int candidate = 0, l = 1, r = *max_element(L.begin(), L.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (getnum(L, mid) >= k) {
                candidate = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }

        return candidate;
    }
};