/*
Implement int sqrt(int x).
Compute and return the square root of x.
*/
#include "main.hpp"
class Solution {
private:
    double precision;
public:
    Solution() {
        precision = 0.1;
    }
    double mySqrt(int x) {
        if(x<0)
            return -1;

        long double i = 0;
        long double j = x/2+1;
        if(x<1)
            j = 1;

        while(j-i>=precision) {
            long double mid = i+(j-i)/2;
            long double product = mid*mid;
            if(product-x<=precision)
                return mid;
            else if(product<x)
                i = mid;
            else 
                j = mid;
        }
        return j;
    }
};
