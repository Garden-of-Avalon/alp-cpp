//  There is a list of sorted integers from 1 to n. Starting from left to right,
//  remove the first number and every other number afterward until you reach the
//  end of the list.

// Repeat the previous step again, but this time from right to left, remove the
// right most number and every other number from the remaining numbers.

// We keep repeating the steps again, alternating left to right and right to
// left, until a single number remains.

// Find the last number that remains starting with a list of length n.

// Example:

// Input:
// n = 9,
// 1 2 3 4 5 6 7 8 9
// 2 4 6 8
// 2 6
// 6

// Output:
// 6

// iteration corresponding to ref
class Solution {
  public:
    int lastRemaining(int n) {
        map<int, int> n_val;
        n_val[1] = 1;

        for (int temp = n; temp > 1; temp /= 2)
            n_val.emplace(temp, 0);

        for (auto it = next(n_val.begin()); it != n_val.end(); ++it)
            it->second = 2 * (1 + it->first / 2 - n_val[it->first / 2]);

        return n_val[n];
    }
};

// dp same as the ref - MLE
class Solution {
  public:
    int lastRemaining(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;

        for (int i = 2; i < n + 1; ++i)
            dp[i] = 2 * (1 + i / 2 - dp[i / 2]);

        return dp[n];
    }
};

// ref: key concept mirroring
class Solution {
  public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};

// brute force - TLE
class Solution {
  public:
    int lastRemaining(int n) {
        list<int> temp(n);
        iota(temp.begin(), temp.end(), 1);

        // cout << " size " << temp.size() << '\n';

        while (temp.size() > 1) {
            for (auto i = temp.begin(); i != temp.end(); ++i) {
                i = temp.erase(i);
                if (i == temp.end())
                    break;
            }
            // for(auto &&x: temp)
            //     cout << x << ' ';
            // cout << '\n';

            if (temp.size() == 1)
                return temp.front();

            for (auto i = prev(temp.end());; advance(i, -2)) {
                i = temp.erase(i);
                if (i == temp.begin() || i == next(temp.begin()))
                    break;
            }

            // for(auto &&x: temp)
            //     cout << x << ' ';
            // cout << '\n';
        }

        return temp.front();
    }
};