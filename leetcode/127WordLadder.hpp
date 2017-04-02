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
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        unordered_set<string> wordDict(words.begin(), words.end());
        unordered_map<string, int> m;
        queue<string> q;  
        q.push(beginWord);
        m[beginWord] = 1;
        while(!q.empty())  
        {  
            string word = q.front();  
            q.pop();
            for(int i =0; i< word.size(); i++)  
            {  
                string newWord = word;  
                for(int j = 'a'; j <= 'z'; j++)  
                {  
                    newWord[i] = j;
                    if(newWord == endWord) return m[word]+1;  
                    if(wordDict.count(newWord)==1 && m.count(newWord)==0)
                    {  
                        q.push(newWord);
                        m[newWord] = m[word]+1;
                    }  
                }  
            }  
        }  
        return 0;  
    }  
};
