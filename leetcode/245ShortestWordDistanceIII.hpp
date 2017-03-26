This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list. 


class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int i=-1, j=-1, res=INT_MAX;
        for(int k=0; k<words.size(); k++) {
            int t=i;
            if(words[k] == word1 && i!=-1) i=k;
            if(words[k] == word2 && j!=-1) j=k;
            if(i!=-1&&j!=-1) {
                if(word1==word2 && t!=-1 && t!=j)
                    res = min(res, abs(t-j));
                else if (i!=j)
                    res = min(res, abs(i-j));
            }
        }
        return res;
    }
};
