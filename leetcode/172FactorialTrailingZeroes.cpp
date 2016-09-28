Given an integer n, return the number of trailing zeroes in n!.

class Solution {
public:
    int trailingZeroes(int n) {
        //n/5+n/25+n/125
        long long r = 0, t = 5;
        while(n>=t) {
            r += n/t;
            t*=5;
        }
        return r;
    }
};
