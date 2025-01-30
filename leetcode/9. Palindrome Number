Determine whether an integer is a palindrome. Do this without extra space.

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x&&(x%10==0)))
            return false;
        int i = 0;
        while(x>=i) {
            if(x==i)
                return true;
            i = 10*i+ x%10;
            x = x/10;
        }
        return x == i/10;
    }
};
