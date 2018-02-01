Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".



class Solution {
public:
    int findNextSlash(string path, int b) {
        for(b=b+1; b<path.size(); b++) {
            if(path[b]=='/')
                return b;
        }
        return path.size();
    }
    string simplifyPath(string path) {
        stack<string> p;
        
        int begin = findNextSlash(path, -1);
        while(begin != path.size()) {
            int end = findNextSlash(path, begin);
            if(end-begin < 2) {
                begin = end;
                continue;
            }
            string t = string(path, begin+1, end-begin-1);
            begin = end;
            if(t == string("."))
                continue;
            if(t == string("..")) {
                if(!p.empty())
                    p.pop();
                continue;
            }
            p.push(t);
        }
        
        string s;
        while(!p.empty()) {
            reverse(p.top().begin(), p.top().end());
            s += p.top();
            p.pop();
            s += string("/");
        }
        if(s.empty()) {
            return string("/");
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
