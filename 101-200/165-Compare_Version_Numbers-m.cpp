// Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise
// return 0.

// You may assume that the version strings are non-empty and contain only digits
// and the . character. The . character does not represent a decimal point and
// is used to separate number sequences. For instance, 2.5 is not "two and a
// half" or "half way to version three", it is the fifth second-level revision
// of the second first-level revision.

// Here is an example of version numbers ordering:

// 0.1 < 1.1 < 1.2 < 13.37

class Solution {
  public:
    int compareVersion(string version1, string version2) {
        replace(version1.begin(), version1.end(), '.', ' ');
        replace(version2.begin(), version2.end(), '.', ' ');

        istringstream vs1(version1), vs2(version2);

        vector<int> ver1(istream_iterator<int>(vs1), {}),
            ver2(istream_iterator<int>(vs2), {});

        int sz = max(ver1.size(), ver2.size());
        ver1.resize(sz);
        ver2.resize(sz);

        for (int i = 0; i < sz; ++i) {
            if (ver1[i] > ver2[i])
                return 1;
            else if (ver1[i] < ver2[i])
                return -1;
        }

        return 0;
    }
};