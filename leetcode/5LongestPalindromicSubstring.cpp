/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

#include <string>

using namespace std;

class Solution {
public:
    void longestPalindrome(string s, int b, int e, string& t) {
        for(; b>=0 && e<(int)s.size()&&s[b] == s[e]; b--, e++) {
        }
        if(e-b-1 > t.size())
            t = string(s, b+1, e-b-1);
    }
    string longestPalindrome(string s) {
        string t;
        for(int i=0; i<(int)s.length(); i++) {
            if(i!=(int)s.length()-1 && s[i] == s[i+1])
                longestPalindrome(s, i, i+1, t);
            longestPalindrome(s, i, i, t);
        }
        return t;
    }
};

int main()
{
    Solution s;
    s.longestPalindrome("a");
}
