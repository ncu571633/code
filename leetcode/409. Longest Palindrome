Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.


class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for(int i=0; i<s.size(); i++) {
            if(m.count(s[i]))
                m[s[i]] ++;
            else
                m[s[i]] = 1;
        }
        int count = 0, add = 0;
        for(map<char, int>::iterator it=m.begin(); it!=m.end(); it++) {
            if(it->second % 2 == 0)
                count += it->second;
            else
                count += it->second-1, add = 1;
        }
        return count+add;
    }
};
