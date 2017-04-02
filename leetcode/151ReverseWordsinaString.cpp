 Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the". 

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())
            return ;
        string t;
        istringstream in(s);
        for(string word; in>>word; ) {
            reverse(word.begin(), word.end());
            t = t+word+string(" ");
        }
        s = t;
        if(!s.empty()) {
            s.pop_back();
            reverse(s.begin(), s.end());
        }
    }
};


class Solution {
public:
    void reverseWords(string&s, int i, int j) {
        while(i<j)
            swap(s[i++], s[j--]);
    }
    void reverseWords(string &s) {
        reverseWords(s, 0, s.size()-1);
        
        for(int i=0, j=0; j<s.size(); ) {
            while(s[i]==' ' && j<s.size())
                i++, j++;
            while(s[j]!=' ' && j<s.size())
                j++;
            reverseWords(s, i, j-1);
            i = j;
        }
    }
};
