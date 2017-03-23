#if 0
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:

    pattern = "abab", str = "redblueredblue" should return true.
    pattern = "aaaa", str = "asdasdasdasd" should return true.
    pattern = "aabb", str = "xyzabcxzyabc" should return false.
#endif

#include "main.hpp"
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        return helper(pattern, 0, str, 0, m1, m2);
    }
    bool helper(string& pattern, size_t p, string& str, size_t r, 
            unordered_map<char, string> &m1, unordered_map<string, char>& m2) {
        if(p==pattern.size() && r==str.size())
            return true;
        if(p==pattern.size() || r==str.size())
            return false;

        char c = pattern[p];
        for(size_t i=r; i<str.size(); i++) {
            string t = str.substr(r, i-r+1);
            if(m1.count(c)==0 && m2.count(t)==0) {
                m1[c] = t;
                m2[t] = c;
                if(helper(pattern, p+1, str, i+1, m1, m2))
                    return true;
                m1.erase(c);
                m2.erase(t);
            }
            else if(m1.count(c) && m2.count(t)) {
                if((m1[c]!=t) || (m2[t]!=c))
                    return false;
                if(helper(pattern, p+1, str, i+1, m1, m2))
                    return true;
            }
        }
        return false;
    }
};


#include "291WordPatternII.hpp"

int main(int argc, char** argv) {
    
    Solution s;
    cout<<s.wordPatternMatch("abab", "redblueredblue")<<endl;   //1
    cout<<s.wordPatternMatch("aaaa", "asdasdasdasd")<<endl; // 1
    cout<<s.wordPatternMatch("aabb", "xyzabcxzyabc")<<endl; // 0
    return 1;
}
