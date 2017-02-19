 Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"

Output:

4

One possible longest palindromic subsequence is "bbbb".

Example 2:
Input:

"cbbd"

Output:

2

One possible longest palindromic subsequence is "bb". 

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty())
            return 0;
        vector<vector<int>> m(s.size(), vector<int>(s.size(), 0));
        for(int i=s.size()-1; i>=0; i--) {
            m[i][i] = 1;
            for(int j=i+1; j<s.size(); j++) {
                if(s[i] == s[j])
                    m[i][j] = m[i+1][j-1]+2;
                else
                    m[i][j] = max(m[i+1][j], m[i][j-1]);
            }
        }
        return m[0].back();
    }
};
