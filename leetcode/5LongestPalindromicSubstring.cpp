Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"



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
