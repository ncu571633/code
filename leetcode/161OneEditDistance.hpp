Given two strings S and T, determine if they are both one edit distance apart.

class Solution {
public:
    bool isOneEditDistance(string s, string t) {

        if (s.size() < t.size()) {
            swap(s, t);
        }
        if(s.size()-t.size() > 1)
            return false;
        if (s.size() == t.size()) {
            int diff = 0;
            for(int i=0; i<s.size(); i++) {
                if(s[i] != t[i]) {
                    diff ++;
                }
                if (diff > 1)
                    return false;
            }
            return true;
        }
        // s.size() - t.size() == 1
        for(int i=0; i<t.size(); i++) {
            if(s[i] != t[i])
                return s.substr(i+1) == t.substr(i);
        }
    }
}
