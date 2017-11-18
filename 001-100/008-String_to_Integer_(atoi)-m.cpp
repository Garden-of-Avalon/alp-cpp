// Implement atoi to convert a string to an integer.
// Hint: Carefully consider all possible input cases. If you want a challenge,
// please do not see below and ask yourself what are the possible input cases.
// Notes: It is intended for this problem to be specified vaguely (ie, no given
// input specs). You are responsible to gather all the input requirements up
// front.

// fuck "+-2"
// fuck "      010"
// fuck "      -   320"
// fuck " b11228552307"
// fucking quesion
class Solution {
  public:
    int myAtoi(string str) {
        long int result = 0;
        int sign = 1;
        auto isnum = [](const char &c) { return c >= '0' && c <= '9'; };

        auto i = str.find_first_not_of(' ');

        if (str[i] == '-' || str[i] == '+')
            sign = (str[i++] == '-') ? -1 : 1;

        if (isnum(str[i])) {
            while (i < str.size() && isnum(str[i])) {
                if (sign > 0)
                    (result *= 10) += static_cast<int>(str[i++] - '0');
                else
                    (result *= 10) -= static_cast<int>(str[i++] - '0');

                if (result > INT_MAX)
                    return INT_MAX;

                if (result < INT_MIN)
                    return INT_MIN;
            }
        }

        return result;
    }
};

// class Solution {
//   public:
//     int myAtoi(string str) {
//         long int result = 0;
//         int sign = 1;
//         auto isnum = [](char c) { return c >= '0' && c <= '9'; };

//         auto iter = find_if(str.begin(), str.end(), isnum);
//         if (iter != str.end()) {
//             auto i = str.find_first_not_of(' ');
//             if (str[i] == '-' || str[i] == '+' || isnum(str[i])) {
//                 if (str[i] == '-')
//                     sign = -1;

//                 if (isnum(str[i]) || distance(str.begin(), iter) == i + 1) {
//                     while (iter != str.end() && isnum(*iter)) {
//                         if (sign > 0)
//                             (result *= 10) += static_cast<int>(*iter++ -
//                             '0');
//                         else
//                             (result *= 10) -= static_cast<int>(*iter++ -
//                             '0');

//                         if (result > INT_MAX)
//                             return INT_MAX;

//                         if (result < INT_MIN)
//                             return INT_MIN;
//                     }
//                 }
//             }
//         }

//         return result;
//     }
// };