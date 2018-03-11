#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string test_str = "1.2.3.4.5";

    replace(test_str.begin(), test_str.end(), '.', ' ');

    istringstream test_ss(test_str);

    // {} is like istream_iterator<int>() and behaves as "end"
    vector<int> test_v(istream_iterator<int>(test_ss), {});

    for (auto &&n : test_v)
        cout << n << ' ';
    cout << '\n';

    return 0;
}