// Additive number is a string whose digits can form additive sequence.

// A valid additive sequence should contain at least three numbers. Except for
// the first two numbers, each subsequent number in the sequence must be the sum
// of the preceding two.

// For example:
// "112358" is an additive number because the digits can form an additive
// sequence: 1, 1, 2, 3, 5, 8.

// 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

// "199100199" is also an additive number, the additive sequence is: 1, 99, 100,
// 199.

// 1 + 99 = 100, 99 + 100 = 199

// Note: Numbers in the additive sequence cannot have leading zeros, so sequence
// 1, 2, 03 or 1, 02, 3 is invalid.

// Given a string containing only digits '0'-'9', write a function to determine
// if it's an additive number.

// Follow up:
// How would you handle overflow for very large input integers?

// ref
// https://leetcode.com/problems/additive-number/discuss/75567/Java-Recursive-and-Iterative-Solutions
// https://leetcode.com/problems/additive-number/discuss/75576/0ms-concise-C++-solution-(perfectly-handles-the-follow-up-and-leading-0s)
class Solution {
    string stradd(const string &a, const string &b) {
        int an = a.size(), bn = b.size(), carry = 0;
        string sum;
        while (an || bn) {
            int curr_sum =
                (an ? a[--an] - '0' : 0) + (bn ? b[--bn] - '0' : 0) + carry;
            carry = curr_sum / 10;
            sum += '0' + curr_sum % 10;
        }
        if (carry)
            sum += '1';
        reverse(sum.begin(), sum.end());
        return sum;
    }

    bool check(int len1, int len2, const string &num) {
        if (num[0] == '0' && len1 > 1 || num[len1] == '0' && len2 > 1)
            return false;
        string sum;
        string n1 = num.substr(0, len1);
        string n2 = num.substr(len1, len2);
        // n3, n4 ...
        for (int start = len1 + len2; start < num.size(); start += n2.size()) {
            sum = stradd(n1, n2);
            if (num.find(sum, start) != start)
                return false;
            swap(n1, n2);
            swap(n2, sum);
        }
        return true;
    }

  public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int len1 = 1; len1 <= n / 2; ++len1)
            for (int len2 = 1; n - len1 - len2 >= max(len1, len2); ++len2)
                if (check(len1, len2, num))
                    return true;
        return false;
    }
};