Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3



class Solution {
public:
    int numTrees(int n) {
        /*if(n<=1)
            return 1;
        int sum = 0;
        for(int i=1; i<=n; i++) {
            sum += numTrees(i-1)*numTrees(n-i);
        }
        return sum;*/
        
        vector<int> v(n+1, 0);
        v[0] = v[1] = 1;
        for(int i=2; i<=n; i++) {
            for(int j=1; j<=i; j++)
                v[i] += v[j-1]*v[i-j];
        }
        return v[n];
    }
};
