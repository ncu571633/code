 Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z. 

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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* nextNode = root;
        for(int i=0; i<word.size(); i++) {
            if(!nextNode->next[word[i]-'a'])
                nextNode->next[word[i]-'a'] = new TrieNode();
            nextNode = nextNode->next[word[i]-'a'];
        }
        nextNode->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return startsWith(word, true);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix, bool isWord=false) {
        TrieNode* nextNode = root;
        for(int i=0; i<prefix.size(); i++) {
            if(!nextNode->next[prefix[i]-'a'])
                return false;
            nextNode = nextNode->next[prefix[i]-'a'];
        }
        if(isWord)
            return nextNode->isWord;
        else
            return true;        
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
