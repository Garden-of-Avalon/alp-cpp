// Given two strings A and B, find the minimum number of times A has to be
// repeated such that B is a substring of it. If no such solution, return -1.
// For example, with A = "abcd" and B = "cdabcdab".
// Return 3, because by repeating A three times (“abcdabcdabcd”), B is a
// substring of it; and B is not a substring of A repeated two times
// ("abcdabcd").
// Note:
// The length of A and B will be between 1 and 10000.

class Solution {
  public:
    int repeatedStringMatch(string A, string B) {
        string la = A; // "long" A
        while (la.size() < B.size())
            la += A;

        if (la.find(B) != string::npos || (la += A).find(B) != string::npos)
            return la.size() / A.size();

        return -1;
    }
};