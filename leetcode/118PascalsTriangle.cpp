Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]




class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> m;
        for(int i=0; i<numRows; i++) {
            vector<int> v;
            for(int j=0; j<=i; j++) {
                if(j==0 || j==i)
                    v.push_back(1);
                else
                    v.push_back(m[i-1][j-1]+m[i-1][j]);
            }
            m.push_back(v);
        }
        return m;
    }
};
