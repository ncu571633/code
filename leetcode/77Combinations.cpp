/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

#include <vector>
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> sol;
        vector<vector<int>> allSol;
        findComb(n, 1, k, sol, allSol);
        return allSol;
    }
    
    void findComb(int n, int start, int k, vector<int> &sol, vector<vector<int>> &allSol) {
        if(k==0) {
            allSol.push_back(sol);
            return;
        }
        
        for(int i=start; i<=n-k+1; i++) {
            sol.push_back(i);
            findComb(n, i+1, k-1, sol, allSol);
            sol.pop_back();
        } 
    }    
};


