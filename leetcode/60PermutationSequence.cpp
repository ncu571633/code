/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void getPermutation(int n, int k, int& count, string& s, vector<bool>& visited) {
        if(s.size()==n)
            count++;
        if(count==k)
            return;
        for(int i=0; i<n; i++) {
            if(visited[i])
                continue;
            s.push_back(i+'1');
            visited[i] = true;
            getPermutation(n, k, count, s, visited);
            if(count==k)
                return;
            s.pop_back();
            visited[i] = false;
        }
    }
    string getPermutation(int n, int k) {
        string s;
        vector<bool> visited(n, 0);
        int count = 0;
        getPermutation(n, k, count, s, visited);
        return s;
    }
};

int main()
{
    Solution s;
    s.getPermutation(2, 2);
}
