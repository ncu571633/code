 Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:

Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"


class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++)
            m[s[i]]++;
        unordered_map<char, bool> visited;
        string ret("0");
        for(int i=0; i<s.size(); i++) {
            m[s[i]]--;
            if(visited[s[i]])
                continue;
            while(s[i]<ret.back() && m[ret.back()]>0) {
                visited[ret.back()] = 0;
                ret.pop_back();
            }
            ret += s[i];
            visited[s[i]] = 1;
        }
        return ret.substr(1);
    }
};
