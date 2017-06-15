
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code". 

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() || !wordDict.size())
            return false;
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        vector<int> v(s.size()+1, 0);
        v[0] = 1;
        for(int i=0; i<s.size()+1; i++) {
            for(int j=0; j<i; j++) {
                if(v[j] && m.count(s.substr(j, i-j))) {
                    v[i] = true;
                    break;
                }
            }
        }
        return v.back();
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if(!n || !wordDict.size())
            return false;
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        vector<int> v(n+1, 0);
        v[0] = 1;
        for(int i=1; i<n+1; i++) {
            for(int j=i; j<n+1; j++) {
                if(!v[j] && v[i-1] && m.count(s.substr(i-1, j-i+1))) {
                    v[j] = true;
                }
            }
        }
        return v.back();
    }
};
