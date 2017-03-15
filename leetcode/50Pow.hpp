Implement pow(x, n). 

class Solution {
public:
    double myPow(double x, int n) {
        if (n==0)
            return 1;
        if(n<0)
            return 1/myPow(x, -n);

        double ret = myPow(x, n/2);
        ret = ret*ret;
        if(n%2)       
            ret = ret*x;
        return ret;
    }
};

Runtime error: n<0 and 1/0


class Solution {
public:
    double myPow(double x, int n) {
        if (n==0)
            return 1;
        if(n==-1)
            return 1/x;

        double ret = myPow(x, n/2);
        ret = ret*ret;
        if(n%2) {     
            if(n>0) ret = ret*x;
            else ret = ret*(1/x);
        }
        return ret;
    }
};
