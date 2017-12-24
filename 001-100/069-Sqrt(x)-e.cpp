// Implement int sqrt(int x).
// Compute and return the square root of x.

// https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
class Solution {
  public:
    int mySqrt(int x) {
        long r = x;
        while (r * r > x)
            r = (r + x / r) / 2;
        return r;
    }
};