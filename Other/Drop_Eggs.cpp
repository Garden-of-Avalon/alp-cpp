// ref: 375
// There is a building of 100 floors. If an egg drops from the Nth floor or
// above, it will break. If it's dropped from any floor below, it will not
// break. You're given two eggs. Find N, while minimizing the number of drops
// for the worst case.

#include <climits>
#include <vector>

// #include <limits>
// std::numeric_limits<int>::max()

using namespace std;

// 2 egg special way:
// Total k floors, 2 eggs
// V = vector(x) represents the floors to throw 1st egg, x is the tries number
// V[n-1] = k
// Because we are condering the worst case, so no matter how,
// the total tests number should be x,
// break (left) or not break (right), the remaining steps are equal
// V[i] - V[i-1] = x - i
//    => V[i-1] = V[i] - (x - i)
//
// Because we do not know the n at the beginning, consider reverse order of V
// RV[j] = RV[j-1] - j
// Example of 100 floors:
// 99 = 100 - 1, 97 = 100 - 2, ...
// 100 99 97 94 90 85 79 72 64 55 45 34 22 9
// x = 14

int drop2eggs(int k) {
    vector<int> RV = {k};

    int curr_f;
    while ((curr_f = RV.back() - static_cast<int>(RV.size())) > 0)
        RV.push_back(curr_f);

    return RV.size();
}

// more general: m eggs and k floors
// O(nk^2)
int drop_n_k_dp(int n, int k) {
    // EF[i][j] the min number (to handle worst cases) of i eggs and j floors
    vector<vector<int>> EF(n + 1, vector<int>(k + 1, INT_MAX));

    // no floor, 0 try; 1 floor, 1 try
    for (int i = 1; i <= n; ++i) {
        EF[i][0] = 0;
        EF[i][1] = 1;
    }

    // 1 eggs, j try
    for (int j = 1; j <= k; ++j)
        EF[1][j] = j;

    // there should be optimization
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= k; ++j)
            for (int p = 1; p <= j; ++p)
                // right: the worst case
                EF[i][j] =
                    min(EF[i][j], 1 + max(EF[i - 1][p - 1], EF[i][j - p]));

    return EF[n][k];
}

// even better way
// ref: https://brilliant.org/wiki/egg-dropping/
// binomial
// O(nlogk)
// Evaluates sum of C(x,1) to C(x, n), compare to k
bool binomial_less(int x, int n, int k) {
    long long ans = 0;
    long long binomial = 1;

    for (int i = 1; i <= n; i++) {
        (binomial *= x + 1 - i) /= i; // must be integer
        if ((ans += binomial) > k)
            break;
    }

    return ans < k;
}

// n eggs, k floors
int drop_n_k(int n, int k) {
    int mid, r = k, l = 1;

    // lower_bound(k)
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (binomial_less(mid, n, k))
            l = mid + 1;
        else
            r = mid - 1;
    }

    return l;
}

int main() {
    for (int i = 2; i < 5; ++i) {
        for (int j = 3; j < 200; ++j)
            cout << drop_n_k_dp(i, j) << "--" << drop_n_k(i, j) << ' ';
        cout << '\n';
    }
    return 0;
}