//  Given an integer n, return 1 - n in lexicographical order.

// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

// Please optimize your algorithm to use less time and space. The input size may
// be as large as 5,000,000.

class Solution {
  public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for (int i = 1, curr = 1; i <= n; ++i) {
            ret.push_back(curr);
            if (curr * 10 <= n)
                curr *= 10;
            else if (curr % 10 != 9 && curr + 1 <= n) {
                ++curr;
            } else {
                // for 300
                // from 199 to 2, 299 to 3, 99 to 1 (1 won't be added again)
                while ((curr / 10) % 10 == 9)
                    curr /= 10;
                curr = curr / 10 + 1;
            }
        }
        return ret;
    }
};

// TLE for 23489
// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<string> ss;
//         for(int i = 1; i <= n; ++i)
//             ss.push_back(to_string(i));
//         sort(ss.begin(), ss.end());
//         vector<int> ret;
//         for(auto &&s: ss)
//             ret.push_back(stoi(s));
//         return ret;
//     }
// };