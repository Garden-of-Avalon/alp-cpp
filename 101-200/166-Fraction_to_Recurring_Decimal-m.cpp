// Given two integers representing the numerator and denominator of a fraction,
// return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in
// parentheses.

// For example,

//     Given numerator = 1, denominator = 2, return "0.5".
//     Given numerator = 2, denominator = 1, return "2".
//     Given numerator = 2, denominator = 3, return "0.(6)".

class Solution {
  public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator)
            return "0";

        string ret;
        if (numerator < 0 ^ denominator < 0)
            ret = '-';

        using ll = long long;
        ll nu = llabs(numerator), de = llabs(denominator);

        ret += to_string(nu / de);
        nu %= de;
        if (!nu)
            return ret;

        ret += '.';

        unordered_map<ll, int> records; // remain, index
        records.emplace(nu, ret.size());

        while (nu) {
            nu *= 10;
            ret += to_string(nu / de);
            nu %= de;
            if (records.find(nu) != records.end()) {
                ret.insert(records[nu], 1, '(');
                return ret + ')';
            }
            records.emplace(nu, ret.size());
        }

        return ret;
    }
};