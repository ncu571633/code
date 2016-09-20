 Given an integer, write a function to determine if it is a power of three. 
 
 class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1 || n==3)
            return true;
        if(n%3 == 0 && n)
            return isPowerOfThree(n/3);
        return false;
    }
};
