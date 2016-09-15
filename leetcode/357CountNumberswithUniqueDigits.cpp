Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99]) 

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        n = min(n, 10);
        vector<int> v(n+1, 9);
        v[0] = 1;
        for(int i=2; i<=n; i++)
            v[i] = v[i-1] * (9-i+2);
        int sum = 0;
        for(int i=0; i<=n; i++)
            sum+=v[i];
        return sum;
    }
};



/*
n=0   1
n=1   9
n=2   9*9
n=3   9*9*8
*/
