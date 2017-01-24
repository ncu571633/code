/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        if(s.empty())
            return true;
        vector<int> v(256, 0);
        for(int i=0; i<s.size(); i++) {
            v[s[i]]++, v[t[i]]--;
        }
        for(int i=0; i<256; i++) {
            if(v[i] != 0)
                return false;
        }
        return true;
    }
};
