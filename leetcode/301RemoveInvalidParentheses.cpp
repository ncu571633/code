 Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:

"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> v;
        if(s.empty()) {
            v.push_back(s);
            return v;
        }
        queue<string> q;
        set<string> visit;
        q.push(s);
        visit.insert(s);
        int found = false;
        while(!q.empty()) {
            s = q.front();
            q.pop();
            
            if(isValid(s)) {
                found = true;
                v.push_back(s);
            }
            if(found == true) {
                continue;
            }
            for(int i=0; i<s.size(); i++) {
                if(s[i] != '(' && s[i] != ')')
                    continue;
                string sub = s;
                sub.erase(i, 1);
                if(!visit.count(sub)) {
                    q.push(sub);
                    visit.insert(sub);
                }
            }
        }
        return v;
    }
    
    bool isValid(string s) {
        int sum = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(')
                sum ++;
            if(s[i] == ')')
                sum --;
            if(sum<0)
                return false;
        }
        return sum==0;
    }
};
