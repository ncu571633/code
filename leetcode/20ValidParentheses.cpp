/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:

    bool isValid(string s) {
        stack<char> temp;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                temp.push(s[i]);
                continue;
            }

            if( temp.empty()
            ||  (s[i]==')' && temp.top()!='(')
            ||  (s[i]=='}' && temp.top()!='{')
            ||  (s[i]==']' && temp.top()!='['))
				return false;

            temp.pop();
        }
        if(temp.empty())
            return true;
        return false;
    }
};
