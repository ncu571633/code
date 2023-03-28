 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size())
            return false;
        if(!s1.size())
            return s2 == s3;
        if(!s2.size())
            return s1 == s3;
        if(s1[0] == s3[0] && s2[0] != s3[0])
            return isInterleave(s1.substr(1), s2, s3.substr(1));
        if(s2[0] == s3[0] && s1[0] != s3[0])
            return isInterleave(s1, s2.substr(1), s3.substr(1)); 
        if(s1[0] == s3[0] && s2[0] == s3[0])
            return isInterleave(s1, s2.substr(1), s3.substr(1)) || isInterleave(s1.substr(1), s2, s3.substr(1)); 
        return false;
    }
};
