// https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
// https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/

// KMP (Knuth Morris Pratt) Pattern Searching

// The naive pattern searching algorithm doesn’t work well in cases where many
// matching characters are followed by a mismatching character

// Key idea: bypass the same characters fast.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// longest proper prefix which is also suffix
// For ABC, proper prefixes are "" A AB, suffix are "" C BC ABC
vector<int> getlps(string &pat) {
    int len = 0, i = 1, m = pat.size();
    vector<int> lps(m);

    while (i < m) {
        if (pat[i] == pat[len]) {
            ++len;
            lps[i++] = len;
        } else if (len == 0)
            lps[i++] = 0;
        else
            len = lps[len - 1];
    }

    return lps;
}

int testlps() {
    vector<string> pats = {"AAAA", "ABCD", "ABAB", "AABB", "ABABCABAB"};

    for (auto &p : pats) {
        cout << "pat";
        for (auto &c : p)
            cout << ' ' << c;
        cout << '\n' << "lps";
        for (auto &c : getlps(p))
            cout << ' ' << c;
        cout << '\n' << endl;
    }

    return 0;
}

vector<int> KMPsearch(string &pat, string &txt) {
    vector<int> ret;
    int m = pat.size(), n = txt.size();

    auto lps = getlps(pat);
    int i = 0, j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            ++i;
            ++j;
        }

        if (j == m) {
            ret.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && txt[i] != pat[j])
            j ? j = lps[j - 1] : ++i;
    }

    return ret;
}

int main() {
    testlps();

    string txt = "ABABDABACDABABCABABABABDABACDABABCABAB";
    string pat = "ABABCABAB";

    cout << "txt " << txt << endl;
    cout << "pat " << pat << endl;

    cout << "find pattern at index:" << endl;
    for (auto &i : KMPsearch(pat, txt))
        cout << i << ' ' << txt.substr(i, pat.size()) << endl;

    return 0;
}

// output:
// pat A A A A
// lps 0 1 2 3

// pat A B C D
// lps 0 0 0 0

// pat A B A B
// lps 0 0 1 2

// pat A A B B
// lps 0 1 0 0

// pat A B A B C A B A B
// lps 0 0 1 2 0 1 2 3 4

// txt ABABDABACDABABCABABABABDABACDABABCABAB
// pat ABABCABAB
// find pattern at index:
// 10 ABABCABAB
// 29 ABABCABAB