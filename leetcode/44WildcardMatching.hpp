/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
#include "main.hpp"
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.empty() && p.empty())
            return true;
        if(!s.empty() && p.empty())
            return false;
            
        if(p[0]=='*') {
            int j=1;
            for(; j<p.size(); j++) {
                if(p[j]!='*')
                    break;
            }
            if(j == p.size())
                return true;
            for(int i=0; i<s.size(); i++) {
                if(isMatch(s.substr(i), p.substr(j)))
                    return true;
            }
            return false;
        } else if(p[0]=='?') {
            if(s.size()==0)
                return false;
            return isMatch(s.substr(1), p.substr(1));
        } else if(s[0] != p[0])
            return false;
        else
            return isMatch(s.substr(1), p.substr(1));
    }
};
