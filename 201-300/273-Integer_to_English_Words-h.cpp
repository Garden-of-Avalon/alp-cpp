// Convert a non-negative integer to its english words representation. Given
// input is guaranteed to be less than 231 - 1.
// For example,
// 123 -> "One Hundred Twenty Three"
// 12345 -> "Twelve Thousand Three Hundred Forty Five"
// 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
// Seven"

class Solution {
    string smallNumToWords(int num) {
        vector<string> less20 = {"One",       "Two",      "Three",   "Four",
                                 "Five",      "Six",      "Seven",   "Eight",
                                 "Nine",      "Ten",      "Eleven",  "Twelve",
                                 "Thirteen",  "Fourteen", "Fifteen", "Sixteen",
                                 "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"Twenty",  "Thirty", "Forty",  "Fifty",  "Sixty",
                               "Seventy", "Eighty", "Ninety"};
        int t = 0;
        string result;
        // assume 123
        if ((t = num / 100) > 0) {
            // t = 1
            result += less20[t - 1] + " Hundred";
        }
        if ((t = num % 100) > 19) {
            if (!result.empty())
                result += " ";
            // t = 23, 23 / 10 - 2 = 0
            result += tens[t / 10 - 2];
            if (t % 10 > 0)
                result += " " + less20[t % 10 - 1];
        } else if ((t = num % 20) > 0) {
            if (!result.empty())
                result += " ";
            // t = 3
            result += less20[t - 1];
        }
        return result;
    }

  public:
    string numberToWords(int num) {
        if (!num)
            return "Zero";

        string result;
        if (num >= 1000000000)
            result += smallNumToWords(num / 1000000000) + " Billion";
        num %= 1000000000;
        if (num >= 1000000) {
            if (!result.empty())
                result += " ";
            result += smallNumToWords(num / 1000000) + " Million";
        }
        num %= 1000000;
        if (num  >= 1000) {
            if (!result.empty())
                result += " ";
            result += smallNumToWords(num / 1000) + " Thousand";
        }
        num %= 1000;
        if (!result.empty() && num)
            result += " ";
        result += smallNumToWords(num);

        return result;
    }
};