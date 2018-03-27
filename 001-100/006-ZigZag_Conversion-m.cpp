// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
// of rows like this: (you may want to display this pattern in a fixed font for
// better legibility)
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a
// number of rows:
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

// TODO: better understanding way

class Solution {
  public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(!n || numRows == 1)
            return s;

        // In given example, NG is tail
        int tail = n % (2 * numRows - 2);
        // P A Y P is the first block
        int blocks = n / (2 * numRows - 2);
        int linelength[numRows];

        // update linelength
        linelength[0] = blocks;
        linelength[numRows - 1] = blocks;
        for (int i = 1; i < numRows - 1; ++i) {
            linelength[i] = 2 * blocks;
        }
        for (int i = 0; i < tail; ++i) {
            if (i < numRows)
                ++linelength[i];
            else
                ++linelength[2 * numRows - 2 - i];
            // e.g. i = 3, 2 * numRows - 2 - 3 = 1
            // i.e. ++linelength[1]; (second line)
        }

        string result = s;
        int j, currLen = 0;
        for (int i = 0; i < numRows; ++i) {
            // first line, last line, or middle lines even indice
            // e.g. 2nd line, A () L () I () G
            for (j = currLen; j - currLen < linelength[i]; ++j) {
                if (!i || i == numRows - 1)
                    result[j] = s[(j - currLen) * (2 * numRows - 2) + i];
                else if (!((j - currLen) % 2))
                    result[j] = s[(j - currLen) / 2 * (2 * numRows - 2) + i];
                else
                    result[j] =
                        s[((j - currLen) / 2 + 1) * (2 * numRows - 2) - i];
            }
            currLen += linelength[i];
        }

        return result;
    }
};