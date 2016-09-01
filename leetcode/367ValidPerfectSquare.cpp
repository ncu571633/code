/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True

Example 2:

Input: 14
Returns: False

*/

#include <iostream>
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        int i = 1, j = num;
        while(i<=j) {
            // long long to avoid overflow
            long long k = i + (j-i)/2;
            if(k*k == num)
                return true;
            if(k*k > num)
                j = k-1;
            else
                i = k+1;
        }
        return false;
    }
};

int main()
{
    Solution s;
    std::cout<<s.isPerfectSquare(104976);
}
