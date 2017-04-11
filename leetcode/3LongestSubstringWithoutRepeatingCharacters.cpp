Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0, j=0;
        bool c[256];
        memset(c, 0, 256);
        int len = 0;
        while(j<s.size())
        {
            if(c[ s[j] ] == true)
            {
                len = max(len, j-i);
                
                while( s[i] != s[j])
                    c[ s[i] ] = false, i++;
                i++, j++;
            }
            else
            {
                c[ s[j] ] = true;
                j++;
            }
        }
        len = max(len, j-i);
        return len;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, ret = 0;
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++) {
            m[s[i]] ++;
            if(m[s[i]] == 1) {
                ret = max(ret, i-start+1);
            } else {
                while(s[start]!=s[i]) {
                    m[s[start]]--;
                    start++;
                }
                m[s[start]]--;
                start++;
            }
        }
        return ret;
    }
};



