/*
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000. 
*/

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        if(!n)
            return v;
        v.push_back(1);
        for(int i=1; i<n; i++) {
            int j = v[i-1];
            if(j*10 <= n)
            {
                v.push_back(j*10);
                continue;
            }
            if(j == n)
                j = j/10;
            j++;
            while(j%10 == 0)
                j = j/10;
            v.push_back(j);
        }
        return v;
    }
};

int main()
{
    int n = 13;
    Solution s;
    vector<int> v = s.lexicalOrder(n);
    for(int i=0; i<n; i++)
        cout<<v[i]<<endl;
}


