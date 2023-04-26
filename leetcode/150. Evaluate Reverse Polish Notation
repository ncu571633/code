 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


class Solution {
public:
    bool isOperator(string s) {
        return s == string("+") ||
            s == string("-") ||
            s == string("*") ||
            s == string("/");
    }
    int cal(int n1, int n2, string s) {
        switch(s[0]){
        case '+':
            return n1+n2;
        case '-':
            return n1-n2;
        case '*':
            return n1*n2;
        case '/':
            return n1/n2;
        }
        return 0;
    } 
    int evalRPN(vector<string>& tokens) {
        stack<double> s;

        for(int i=0; i<tokens.size(); i++) {
            if(isOperator(tokens[i])) {
                int n2 = s.top();
                s.pop();
                int n1 = s.top();
                s.pop();
                s.push(cal(n1,n2,tokens[i]));
            } else
                s.push(atoi(tokens[i].c_str()));
        }
        return s.top();
    }
};
