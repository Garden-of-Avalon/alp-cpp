// Given two strings S and T, determine if they are both one edit distance
// apart.

class Solution {
    // compare short str,  long str
    bool cmp(string &sh, int i, string &l, int j) {
        while (i < sh.size()) {
            if (sh[i] != l[j])
                return false;
            ++i;
            ++j; // OK
        }
        return j == l.size();
    };

  public:
    bool isOneEditDistance(string s, string t) {
        int sz = min(s.size(), t.size());

        for (int i = 0; i < sz; ++i)
            if (s[i] != t[i])
                if (s.size() < t.size())
                    return cmp(s, i, t, i + 1);
                else if (s.size() > t.size())
                    return cmp(t, i, s, i + 1);
                else
                    return cmp(s, i + 1, t, i + 1);

        return sz == max(s.size(), t.size()) - 1;
    }
};

// method 2
class Solution {
  public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() > t.size())
            return isOneEditDistance(t, s);

        if (t.size() - s.size() > 1)
            return false;

        bool mark = false;
        for (int i = 0, j = 0; j < t.size(); ++i, ++j)
            if (s.size() == 0 || s[i] != t[j])
                if (mark)
                    return false;
                else {
                    mark = true;
                    if (t.size() > s.size())
                        --i;
                }

        return mark;
    }
};