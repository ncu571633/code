

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]


Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]


class Solution {
public:
    void combinationSum3(int k, int n, vector<vector<int>> &m, vector<int> &v, int start) 
    {
        if(n<0)
            return ;
        if(n==0 && v.size()==k) {
            m.push_back(v);
            return ;
        }
        for(int i=start; i<=9; i++) {
            if(n-i<0) return ;
            v.push_back(i);
            combinationSum3(k, n-i, m, v, i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> m;
        vector<int> v;
        combinationSum3(k, n, m, v, 1);
        return m;
    }
};
