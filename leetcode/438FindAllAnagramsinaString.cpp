/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if(s.size()<p.size())
            return v;
        sort(p.begin(), p.end());
        for(int i=0; i<=s.size()-p.size(); i++) {
            string t = string(s, i, p.size());
            sort(t.begin(), t.end());
            if(t == p)
                v.push_back(i);
        }
        return v;
    }
};
*/
#include 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if(s.size()<p.size())
            return v;
        map<char, int> t1, t2;
        for(int i=0; i<p.size(); i++) {
            t1[s[i]] ++, t2[p[i]]++;
        }
        if(t1==t2)
            v.push_back(0);
        for(int i=1; i<=s.size()-p.size(); i++) {
            t1[s[i-1]]--;
            t1[s[i+p.size()-1]]++;
            if(t1 == t2)
                v.push_back(i);
        }
        return v;
    }
};
