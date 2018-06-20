/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int DP[m][n];
        int i, j;
        for(i=0; i<m; i++)
            DP[i][0] = 1;
        for(j=0; j<n; j++)
            DP[0][j] = 1;
        for(i=1; i<m; i++)
            for(j=1; j<n; j++)
                DP[i][j] = DP[i][j-1]+DP[i-1][j];
        return DP[m-1][n-1];
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        if(!m || !n)
            return 1;
        vector<int> v(n, 1);
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                v[j] += v[j-1]; 
            }    
        }
        return v[n-1];
    }
};
