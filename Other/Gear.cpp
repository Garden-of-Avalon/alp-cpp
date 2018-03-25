// There is no question description for this but only my solving codes

// should work for self defined test case as well as input from cin
// (uncomment specific lines)

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// binary search
auto my_lower_bound(vector<array<int, 3>>::iterator b,
                    vector<array<int, 3>>::iterator e, const int &r) {
    if (b == e)
        return e;

    while (b < e) {
        auto mid = b + (e - b) / 2;

        if (mid->at(0) == r)
            return mid;
        else if (mid->at(0) < r)
            b = mid + 1;
        else
            e = mid - 1;
    }
    return b;
}

void test(int n, int d, vector<int> &R, vector<int> &C) {
    vector<array<int, 3>> RCidx(n); // radius, cost, index

    for (int i = 0; i < n; ++i)
        RCidx[i] = {R[i], C[i], i};

    sort(RCidx.begin(), RCidx.end(),
         [](array<int, 3> &a, array<int, 3> &b) { return a[0] < b[0]; });

    for (auto &&r : R) {
        auto it = my_lower_bound(RCidx.begin(), RCidx.end(), d - r);

        if (it == RCidx.end())
            cout << 0;
        else {
            vector<array<int, 3>> cand(it, RCidx.end());
            sort(cand.begin(), cand.end(),
                 [](array<int, 3> &a, array<int, 3> &b) {
                     if (a[1] != b[1])
                         return a[1] < b[1]; // lowest cost
                     else if (a[0] != b[0])
                         return a[0] > b[0]; // largest radius
                     else
                         return a[2] < b[2]; // smallest index
                 });
            cout << cand[0][2] + 1;
        }
        cout << ' ';
    }

    cout << endl;
}

int main() {
    // int n, d;
    // vector<int> R, C;

    //// input logic
    //{
    //	cin >> n >> d >> std::ws;

    //	string buff;
    //	istringstream buffss;

    //	getline(cin, buff);
    //	buffss.str(buff);
    //	copy(istream_iterator<int>(buffss), {}, back_inserter(R));

    //	buffss.clear(); // clear the iostate flags

    //	getline(cin, buff);
    //	buffss.str(buff);
    //	copy(istream_iterator<int>(buffss), {}, back_inserter(C));
    //}

    vector<int> R = {1, 3, 6, 2, 5}, C = {5, 6, 8, 3, 4};
    int n = 5, d = 8; // n == R.size() == C.size()
    // output should be 0 5 4 3 5

    test(n, d, R, C);

    return 0;
}