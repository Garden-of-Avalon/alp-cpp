// Suppose we abstract our file system by a string in the following manner:
// The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
// dir
//     subdir1
//     subdir2
//         file.ext
// The directory dir contains an empty sub-directory subdir1 and a sub-directory
// subdir2 containing a file file.ext.
// The string
// "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
// represents:
// dir
//     subdir1
//         file1.ext
//         subsubdir1
//     subdir2
//         subsubdir2
//             file2.ext
// The directory dir contains two sub-directories subdir1 and subdir2. subdir1
// contains a file file1.ext and an empty second-level sub-directory subsubdir1.
// subdir2 contains a second-level sub-directory subsubdir2 containing a file
// file2.ext.
// We are interested in finding the longest (number of characters) absolute path
// to a file within our file system. For example, in the second example above,
// the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its
// length is 32 (not including the double quotes).
// Given a string representing the file system in the above format, return the
// length of the longest absolute path to file in the abstracted file system. If
// there is no file in the system, return 0.
// Note:
//     The name of a file contains at least a . and an extension.
//     The name of a directory or sub-directory will not contain a ..
// Time complexity required: O(n) where n is the size of the input string.
// Notice that a/aa/aaa/file1.txt is not the longest file path, if there is
// another path aaaaaaaaaaaaaaaaaaaaa/sth.png

// NEED
class Solution {
  public:
    int lengthLongestPath(string input) {
        size_t sz = input.size(), i = 0;
        size_t currline = 0, nextline, lasttab;
        int currlen = 0, maxlen = 0, level = 0;
        vector<int> levellens = {0};

        while (nextline < sz) {
            if ((nextline = input.find('\n', currline)) == string::npos)
                nextline = sz;

            lasttab = input.rfind('\t', nextline);
            if (lasttab != string::npos && lasttab >= currline)
                level = lasttab - currline + 1;
            else
                level = 0;

            currlen = nextline - currline; // including \t
            cout << currlen - level << endl;

            if (input.find('.', currline) < nextline)
                maxlen = std::max(maxlen, levellens[level] + currlen - level + 1);
            else {
                // fuck level + 2
                if (level + 2 > levellens.size())
                    levellens.resize(level + 2);
                levellens[level + 1] = levellens[level] + currlen - level + 1;
            }
            currline = nextline + 1;
        }

        return maxlen ? maxlen - 1 : 0;
    }
};