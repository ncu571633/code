Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

class Solution {
public:
    void generateParenthesis(int n, int left, int right, vector<string>& v, string& s) {
        if(left+right==2*n) {
            v.push_back(s);
            return ;
        }
        if(left<n){
            s.push_back('(');
            generateParenthesis(n, left+1, right, v, s);
            s.pop_back();
        }
        if(right<left){
            s.push_back(')');
            generateParenthesis(n, left, right+1, v, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s;
        int left=0, right=0;
        if(n) 
            generateParenthesis(n, left, right, v, s);
        return v;
    }
};
