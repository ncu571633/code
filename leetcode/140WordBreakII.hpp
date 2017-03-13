 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]. 

class Solution {
public:
    void wordBreak(string s, unordered_set<string> wordDict, int start, string out, vector<string>& ret) {
        if(start >= s.size()) {
            out.pop_back();
            ret.push_back(out);
            return ;
        }
        for(int i=start; i<s.size(); i++) {
            string word = s.substr(start, i-start+1);
            if(wordDict.count(word)) {
                wordBreak(s, wordDict, i+1, out+word+string(" "), ret);
            }
        }
    } 
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ret;
        string out;
        wordBreak(s, unordered_set<string>(wordDict.begin(), wordDict.end()), 0, out, ret);
        return ret;
    }
};


class Solution {
public:
    void wordBreak(string s, unordered_set<string> wordDict, int start, string out, vector<string>& ret, vector<bool>& possible) {
        if(start >= s.size()) {
            out.pop_back();
            ret.push_back(out);
            return ;
        }
        for(int i=start; i<s.size(); i++) {
            string word = s.substr(start, i-start+1);
            if(wordDict.count(word) && possible[i+1]) {
                out = out+word+string(" ");
                int oldSize = ret.size();
                wordBreak(s, wordDict, i+1, out, ret, possible);
                if(ret.size() == oldSize) possible[i+1] = false;
                out.resize(out.size()-word.size()-1);
            }
        }
    } 
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ret;
        string out;
        vector<bool> possible(s.size() + 1, true);
        wordBreak(s, unordered_set<string>(wordDict.begin(), wordDict.end()), 0, out, ret, possible);
        return ret;
    }
};
