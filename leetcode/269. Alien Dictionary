There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
 

The correct order is: "wertf".

Note:

You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.

class Solution {
public:
    string alienOrder(vector<string>& words) {
      unordered_map<char> ch;   // all characters
      set<pair<char, char>> s;  // edges
      unordered_map<char, int> in;
      
      for(auto a: words) {
        ch.insert(a.begin(), a.end());
      }
      for(int i=0; i<words.size()-1; i++) {
        int len = min(words[i].size(), words[i+1].size());
        int j = 0;
        for(; j<len; j++) {
          if(words[i][j] != words[i+1][j]) {
            s.insert({words[i][j], words[i+1][j]});
            break;
          }
        }
        if(j==len && words[i].size()>words[i+1])
          return string("");
      }
      for(auto a: s) {
        in[a.second]++;
      }
      
      queue<char> q;
      string ret;
      for(auto a: in) {
        if(in[a] == 0)
          q.push_back(a);
          ret += string(1, a);
      }
      
      // do a BFS search
      while(!q.empty()) {
        char c = q.top();
        q.pop();
        for(auto a: s) {
          if(a.first == c) {
            in[a.second]--;
            if(in[a.second]==0) {
              q.push_back(a.second);
              ret += string(1, a.second);
            }
          }
        }
      }
      if (ret.size() == ch.size())
        return ret;
      return string("");
    }
}
