Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
	int i=-1, j=-1, ret = INT_MAX;
	for(int k=0; k<words.size(); k++) {
        if(words[k]!=word1 || words[k]!=word2)
            continue;
        if(words[k]==word1) 
            i=k;
        else 
            j=k;
        if(i!=-1 && j!=-1)
            ret = min(ret, abs(i-j));
    }
};
