 Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58. 



class Solution {
public:
    int integerBreak(int n) {
        vector<int> v(n+1, 1);
        for(int i=3; i<=n; i++) {
            for(int j=1; j<i; j++)
                v[i] = max(v[i], max(j, v[j]) * max(i-j, v[i-j]));
        }
        return v[n];
    }
};
