Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


class Solution {
public:
    string frequencySort(string s) {
        if(s.empty())
            return s;
        map<char, int> m;
        for(int i=0; i<s.size(); i++) {
            m[s[i]]++;
        }
        multiset<pair<int, char>> t;
        for(auto it=m.begin(); it!=m.end(); it++) {
            t.insert(make_pair(it->second, it->first));
        }
        string r;
        for(auto it=t.begin(); it!=t.end(); it++) {
            for(int i=0; i<it->first; i++)
                r = r+string(1, it->second);
        }
        reverse(r.begin(), r.end());
        return r;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        if(s.empty())
            return s;
        map<char, int> m;
        for(int i=0; i<s.size(); i++) {
            m[s[i]]++;
        }
        multimap<int, char> t;
        for(auto it=m.begin(); it!=m.end(); it++) {
            t.insert({it->second, it->first});
        }
        string r;
        for(auto it=t.begin(); it!=t.end(); it++) {
            r = r+string(it->first, it->second);
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
