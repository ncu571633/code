/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:

"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

Note: Do not use the eval built-in library function. 
*/
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isOperator(char c) {
        return c=='+' || c=='-' || c=='*' ||  c=='/';
    }
    int calculate(string s) {
        stack<int> s1;
        stack<char> s2;
        int i, j;
        for(i=0, j=0; j<s.size(); ) {
            while(!isOperator(s[j]) && j<s.size())
                j++;
            if(j<s.size()) {
                s1.push(atoi(string(s, i, j-i).c_str()));
                s2.push(s[j]);
                i = j+1;
                j++;
            }
        }
        s1.push(atoi(string(s, i).c_str()));
        
        while(!s2.empty()) {
            i = s1.top();
            s1.pop();
            j = s1.top();
            s1.pop();
            switch(s2.top()) {
                case '+': i=i+j; break;
                case '-': i=j-i; break;
                case '*': i=i*j; break;
                case '/': i=j/i; break;
            }
            s2.pop();
            s1.push(i);
        }
        return s1.top();
    }
};

int main() {
    Solution s;
    s.calculate(string("100000000/1/2/3/4/5/6/7/8/9/10"));
}
