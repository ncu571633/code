/*
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000. 
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        for(int j=1; j<10 && j<=n; j++) {
            v.push_back(j);
            int t = j;
            while(t*10 <= n) {
                t = t*10;
                for(int i=0; i<10 && t+i<=n; i++)
                    v.push_back(t+i);
                t = v.back();
            }
        }
        return v;
    }
};
