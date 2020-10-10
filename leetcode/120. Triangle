Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(!m)
            return 0;
        if(m==1)
            return triangle[0][0];
        int n = triangle[m-1].size();
        vector<int> v1(n, triangle[0][0]);
        vector<int> v2(n, 0);
        for(int i=1; i<m; i++) {
            for(int j=0; j<=i; j++) {
                if(j==0) {
                    v2[j] = triangle[i][j] + v1[j];
                    continue;
                }
                if(j==i) {
                    v2[j] = triangle[i][j] + v1[j-1];
                    continue;
                }
                v2[j] = min(v1[j-1], v1[j]) + triangle[i][j];
            }
            swap(v1, v2);
        }
        int ret = v1[0];
        for(int i=1; i<n; i++)
            ret = min(v1[i], ret);
        return ret;
    }
};
