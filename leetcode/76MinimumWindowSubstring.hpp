 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
            return string("");
        unordered_map<char, int> m;
        for(int i=0; i<t.size(); i++) {
            m[t[i]]++;
        }
        string ret;
        int count=0, minLen = INT_MAX;
        for(int i=0, j=0; j<s.size(); j++) {
            if(!m.count(s[j]))
                continue;
            m[s[j]]--;
            if(m[s[j]]>=0) count++;
            while(count == t.size()) {
                if(minLen > j-i+1) {
                    minLen = j-i+1;
                    ret = s.substr(i, minLen);
                }
                if(m.count(s[i])) {
                    m[s[i]]++;
                    if(m[s[i]]>0) count--;
                }
                i++;
            }
        }
        return ret;
    }
};
