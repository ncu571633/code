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



class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        int n = s.size();
        vector<vector<int>> m(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(s[i] == s[j] && (i-j<2 || m[j+1][i-1]))
                {
                    m[j][i] = 1;
                    if (ret.size() < i-j+1)    
                        ret = s.substr(j, i-j+1);
                }    
                else
                    m[j][i] = 0;
            }
        }
        return ret;
    }
};
