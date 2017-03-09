 Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListSet(wordList.begin(), wordList.end());
        unordered_map<string, int> m;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            string s = q.front();
            q.pop();
            for(int i=0; i<s.size(); i++) {
                for(char c='a'; c<='z'; c++) {
                    string t = s;
                    if(t[i] == c)
                        continue;
                    t[i] = c;
                    if(t == endWord)
                        return m[s]+1;
                    m[t] = 1;
                    
                }
            }
        }
        return 0;
    }
};
