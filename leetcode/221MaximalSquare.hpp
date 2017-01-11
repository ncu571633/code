Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(!m)
            return 0;
        if(m==1) {
            for(int i=0; i<matrix[0].size(); i++)
                if(matrix[0][i]=='1')
                    return 1;
            return 0;
        }
        int n=matrix[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0));
        int s = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(matrix[i][j] == '1')
                    v[i][j]=1, s=1;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++) {
                if(v[i][j]) {
                    v[i][j] = v[i][j]+min(v[i-1][j], min(v[i][j-1], v[i-1][j-1]));
                    s = max(s, v[i][j]);
                }
            }
        }
        return s*s;
    }
};
