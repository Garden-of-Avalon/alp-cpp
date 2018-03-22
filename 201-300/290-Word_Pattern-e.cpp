// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a
// letter in pattern and a non-empty word in str.

// Examples:

//     pattern = "abba", str = "dog cat cat dog" should return true.
//     pattern = "abba", str = "dog cat cat fish" should return false.
//     pattern = "aaaa", str = "dog cat cat dog" should return false.
//     pattern = "abba", str = "dog dog dog dog" should return false.

// Notes:
// You may assume pattern contains only lowercase letters, and str contains
// lowercase letters separated by a single space.

class Solution {
  public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> p_to_s;
        bitset<26> pused;

        istringstream sstr(str);
        string temp;

        for (auto &&p : pattern) {
            if (sstr.eof())
                return false;

            sstr >> temp;
            if (p_to_s.find(temp) == p_to_s.end()) {
                if (pused.test(p - 'a'))
                    return false;
                p_to_s[temp] = p;
                pused.set(p - 'a');
            } else if (p_to_s[temp] != p)
                return false;
        }

        return sstr.eof();
    }
};