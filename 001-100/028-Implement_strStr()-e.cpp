// Implement strStr().
// Returns the index of the first occurrence of needle in haystack, or -1 if
// needle is not part of haystack.

class Solution {
  public:
    int strStr(string haystack, string needle) {
        // this is just call to standard library
        // return haystack.find(needle);

        // C++17, using std::string_view;
        // string_view haystack_view(haystack);
        // for (int i = 0; i < haystack.size() - needle.size() + 1; ++i)
        //     if (haystack_view.substr(i, needle.size()) == needle)
        //         return i;

        // (haystack.size() - needle.size() + 1) won't give a negative int
        int hsz = haystack.size(), nsz = needle.size();
        for (int i = 0; i < hsz - nsz + 1; ++i)
            if (haystack.substr(i, nsz) == needle)
                return i;
        // or implement in C style and use reference to avoid copy

        // KMP algorithm can be used here

        return -1;
    }
};