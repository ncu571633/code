Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> m;
        for(int i=0; i<strs.size(); i++) {
            string s = strs[i];
            map<char, int> t;
            for(int j=0; j<s.size(); j++)
                t[s[j]]++;
            m[t].push_back(s);
        }
        vector<vector<string>> v;
        for(auto it=m.begin(); it!=m.end(); it++) {
            v.push_back(it->second);
        }
        return v;
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(int i=0; i<strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }
        vector<vector<string>> v;
        for(auto it=m.begin(); it!=m.end(); it++) {
            v.push_back(it->second);
        }
        return v;
    }
};
