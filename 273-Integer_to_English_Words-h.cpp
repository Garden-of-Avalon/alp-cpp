// Convert a non-negative integer to its english words representation. Given
// input is guaranteed to be less than 231 - 1.
// For example,
// 123 -> "One Hundred Twenty Three"
// 12345 -> "Twelve Thousand Three Hundred Forty Five"
// 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
// Seven"

class Solution {
  public:
    string numberToWords(int num) {
        std::array<int> vals = {1e9, 1e6, 1e3, 100, 90, 80, 70, 60, 50, 40, 30,
                                20,  19,  18,  17,  16, 15, 14, 13, 12, 11, 10,
                                9,   8,   7,   6,   5,  4,  3,  2,  1};
        std::array<string> words = {
            "Billion", "Million", "Thousand", "Hundred",  "Ninety",
            "Eighty",  "Seventy", "Sixty",    "Fifty",    "Forty",
            "Thirty",  "Twenty",  "Nineteen", "Eighteen", "Seventeen",
            "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve",
            "Eleven",  "Ten",     "Nine",     "Eight",    "Seven",
            "Six",     "Five",    "Four",     "Three",    "Two",
            "One"};
    }
};