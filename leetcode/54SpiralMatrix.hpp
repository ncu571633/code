Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int m = matrix.size();
        if(!m)
            return v;
        int n = matrix[0].size();
        int top=0, bottom=0, left=0, right=0;
        while(true) {
            for(int i=left; i<n-right; i++)
                v.push_back(matrix[top][i]);
            top++;
            if(top+bottom == m)
                break;
                
            for(int i=top; i<m-bottom; i++)
                v.push_back(matrix[i][n-1-right]);
            right++;
            if(left+right == n)
                break;
                
            for(int i=n-1-right; i>=left; i--)
                v.push_back(matrix[m-1-bottom][i]);
            bottom++;
            if(top+bottom == m)
                break;
                
            for(int i=m-1-bottom; i>=top; i--)
                v.push_back(matrix[i][left]);
            left++;
            if(left+right == n)
                break;
        }
        return v;
    }
};
