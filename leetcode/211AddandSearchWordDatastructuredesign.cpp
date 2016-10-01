/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        next.resize(26, nullptr);
        isWord = false;
    }
    vector<TrieNode*> next;
    bool isWord;
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* nextNode = root;
        for(int i=0; i<word.size(); i++) {
            if(!nextNode->next[word[i]-'a'])
                nextNode->next[word[i]-'a'] = new TrieNode();
            nextNode = nextNode->next[word[i]-'a'];
        }
        nextNode->isWord = true;        
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word, int start, TrieNode* nextNode) {
        if(start==word.size())
            return nextNode->isWord;
        for(int i=start; i<word.size(); i++) {
            if(word[i]!='.') {
                int index = word[i]-'a';
                if(!nextNode->next[index])
                    return false;
                return search(word, i+1, nextNode->next[index]);
            } else {
                for(int index=0; index<26; index++) {
                    if(nextNode->next[index])
                        if(search(word, i+1, nextNode->next[index]))
                            return true;
                }
                return false;
            }
        }
        return true;  
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
};

int main()
{
    WordDictionary w;
    w.addWord("abcd");
    cout<<w.search("ab")<<endl;
    cout<<w.search("ab.d")<<endl;
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
