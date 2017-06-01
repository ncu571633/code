You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m)
            return ;
        int n = matrix[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0, k=m-1; j<k; j++, k--) {
                swap(matrix[j][i], matrix[k][i]);   
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
