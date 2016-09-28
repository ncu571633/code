Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 


class Solution {
public:
    void reverse(vector<int>&v, int i, int j) {
        while(i<j)
            swap(v[i++], v[j--]);
    }
    void rotate(vector<int>& v, int k) {
        if(k%v.size()==0)
            return ;
        k = k%v.size();
        reverse(v, 0, v.size()-k-1);
        reverse(v, v.size()-k, v.size()-1);
        reverse(v, 0, v.size()-1);
    }
};
