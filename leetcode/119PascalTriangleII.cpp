Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1]. 


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v1(rowIndex+1, 1);
        if(rowIndex<=1)
            return v1;
        vector<int> v2;
        for(int i=1; i<=rowIndex; i++) {
            for(int j=0; j<=i; j++) {
                if(j==0 || j==i)
                    v2[j] = (1);
                else
                    v2[j] = v1[j-1]+v1[j];
            }
            swap(v1, v2);
        }
        return v1;
    }
};
