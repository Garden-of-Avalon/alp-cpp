// The API: int read4(char *buf) reads 4 characters at a time from a file.

// The return value is the actual number of characters read. For example, it
// returns 3 if there is only 3 characters left in the file.

// By using the read4 API, implement the function int read(char *buf, int n)
// that reads n characters from the file.

// Note:
// The read function may be called multiple times.

// Example 1:

// Given buf = "abc"
// read("abc", 1) // returns "a"
// read("abc", 2); // returns "bc"
// read("abc", 1); // returns ""
// Example 2:

// Given buf = "abc"
// read("abc", 4) // returns "abc"
// read("abc", 1); // returns ""

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    string left;

  public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int sz = 0, fromleft = min(static_cast<int>(left.size()), n);

        sz += fromleft;
        copy(left.begin(), left.begin() + fromleft, buf);
        left = left.substr(fromleft);
        n -= fromleft;

        int tmp = 0;

        while (n > 0 && (tmp = read4(buf + sz))) {
            n -= tmp;
            sz += tmp;
        }

        if (n < 0) {
            left = string(buf + sz + n, buf + sz);
            buf[sz + n] = '\0';
        } else
            buf[sz] = '\0';

        return min(sz + n, sz);
    }
};