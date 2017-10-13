


class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp = 0xffffffff;
        int i = 0;
        while (n >> ++i)
            ;
        temp <<= i;
         
        return (temp ^ (n ^ n >> 1)) == 0xffffffff;
    }
};