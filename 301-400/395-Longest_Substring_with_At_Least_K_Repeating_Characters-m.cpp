//  Find the length of the longest substring T of a given string (consists of
//  lowercase letters only) such that every character in T appears no less than
//  k times.

// Example 1:

// Input:
// s = "aaabb", k = 3

// Output:
// 3

// The longest substring is "aaa", as 'a' is repeated 3 times.

// Example 2:

// Input:
// s = "ababbc", k = 2

// Output:
// 5

// The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
// repeated 3 times.

// two pointers
class Solution {
  public:
    int longestSubstring(string s, int k) {
        int ret = 0;
        array<int, 26> c_ctr;

        for (int uniqueTarget = 1; uniqueTarget <= 26; ++uniqueTarget) {
            c_ctr.fill(0);
            int i = 0, j = 0, unique = 0, noLessThanK = 0;

            while (j < s.size()) {
                int idx;
                if (unique <= uniqueTarget) {
                    idx = s[j++] - 'a';
                    if (c_ctr[idx]++ == 0)
                        ++unique;
                    if (c_ctr[idx] == k)
                        ++noLessThanK;
                } else {
                    idx = s[i++] - 'a';
                    if (c_ctr[idx]-- == k)
                        --noLessThanK;
                    if (c_ctr[idx] == 0)
                        --unique;
                }

                if (unique == uniqueTarget && unique == noLessThanK)
                    ret = max(ret, j - i);
            }
        }
        return ret;
    }
};

// recursion
class Solution {
  public:
    int longestSubstring(string s, int k) {
        if (s.size() < k)
            return 0;
        return helper(s, k, 0, s.size());
    }

    int helper(const string &s, const int &k, int st, int ed) {
        unordered_map<char, int> c_ctr;
        for (int i = st; i < ed; ++i)
            ++c_ctr[s[i]];

        // assume current substr is valid
        bool isValid = true;
        int ret = 0, i = st;
        for (int j = st; j < ed; ++j)
            if (c_ctr[s[j]] < k) {
                isValid = false;
                ret = max(ret, helper(s, k, i, j)); // split[i, j)

                // for next split, two valid must not next to each other
                i = j + 1;
            }

        return isValid ? ed - st : max(ret, helper(s, k, i, ed));
    }
};

// TLE
class Solution {
  public:
    int longestSubstring(string s, int k) {
        int ret = 0, st = 0, ed = s.size() - 1;
        while (st <= ed) {
            unordered_map<char, int> c_ctr; // char ctr of current substring
            int ne = 0, local_max = 0;      // number of chars whose ctr < k
            for (int i = st; i <= ed; ++i) {
                if (c_ctr[s[i]]++ == 0)
                    ++ne;
                if (c_ctr[s[i]] == k)
                    --ne;
                if (ne == 0)
                    local_max = i - st + 1;
            }
            ret = max(ret, local_max);

            int prest = st;

            // 2 valid substring must not be next to each other
            st += local_max + 1;

            local_max = 0;
            for (int j = prest; j <= ed; ++j) {
                if (c_ctr[s[j]]-- == k)
                    ++ne;
                if (c_ctr[s[j]] == 0)
                    --ne;
                if (ne == 0) {
                    local_max = ed - j;
                    break;
                }
            }
            ret = max(ret, local_max);

            ed -= local_max + 1;
            if (ret >= ed - st + 1)
                break;

            // cout << st << ' ' << ret << ' ' << ed << endl;
        }

        return ret;
    }
};

// Wrong
// class Solution {
//   public:
//     int longestSubstring(string s, int k) {
//         // chars first appear, last appear, cnt
//         array<array<int, 3>, 26> cs = {{-1, -1, 0}};

//         for (int i = 0; i < s.size(); ++i) {
//             int pos = s[i] - 'a';
//             if (cs[pos][0] == -1)
//                 cs[pos][0] = i;
//             cs[pos][1] = i;
//             ++cs[pos][2];
//         }

//         // sort by begin index, we don't care which char it is
//         // O(26log26) => O(1)
//         sort(cs.begin(), cs.end(),
//              [](auto &a, auto &b) { return a[0] < b[0]; });

//         int ret = 0;

//         for (int i = 0; i < 26;) {
//             if (cs[i][2] < k)
//                 continue;
//             int j, l = cs[i][0], r = cs[i][1];
//             for (j = i + 1; j < 26; ++j) {
//                 r = max(r, cs[j][1]);
//                 if (cs[j][2] < k)
//                     break;
//             }
//             ret = max(ret, r - l);
//             i = j + 1;
//         }

//         return ret;
//     }
// };