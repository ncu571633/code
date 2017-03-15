Implement pow(x, n). 

class Solution {
public:
    double myPow(double x, int n) {
        bool negPow = n<0 ? true : false;
        n = abs(n);
        double res = 1;
        for(int i=31; i>=0; i--) {
            res = res*res;
            if(n & (1<<i))
                res = res*x;
        }
        if(negPow) res = 1/res;
        return res;
    }
};

