Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.



343. Integer Break

class Solution {
public:
    int integerBreak(int n) {
        int v[n+1];
        v[0] = 0;
        v[1] = 1;
        for(int i=2; i<=n; i++)
        {
            int value = 0;
            for(int j=1; j<=i/2; j++)
            {
                value = max(value, v[j] * v[i-j]);
                value = max(value, j * v[i-j]);
                value = max(value, v[j] * (i-j));
                value = max(value, j * (i-j));
            }
            v[i] = value;
        }
        return v[n];
    }
};