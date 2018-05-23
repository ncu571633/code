Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1

Example 2:

Input: [2,2,2,0,1]
Output: 0

class Solution {
public:
    int findMin(vector<int>& v) {
        int i=0, j = v.size()-1;
        while(i<j)
        {
            if(v[i] < v[j])
                return v[i];
            if(v[i] == v[j])
                i++;
            else
            {
                int k = (i+j)/2;
                if(v[k] <= v[j])
                    j = k;
                else
                    i = k+1;
            }
        }
        return v[i];
    }
};
