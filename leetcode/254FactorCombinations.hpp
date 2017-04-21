Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 

Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
 

Examples: 
input: 1
output: 

[]
input: 37
output: 

[]
input: 12
output:

[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:

[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]



class Solution {
public:
    vector<vector<int>> getFactors(int n) {
      vector<vector<int>> ret;
      if(n<=1)
        return ret;
      vector<int> v;
      getFactors(n, ret, v, 2);
      return ret;
    }
    void getFactors(int n, vector<vector<int>>& ret, vector<int>& v, int start) {
      if (n==1) {
        ret.push_back(v);
        return ;
      }
      for(int i=start; i<=n/2; i++) {
        if(n%i == 0) {
            v.push_back(i);
            getFactors(n/i, ret, v, i);
            v.pop_back();
        }
      }
    }
}
