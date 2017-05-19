The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence. 

class Solution {
public:
    string getNext(string s) {
        int count = 1;
        string t;
        for(int i=1; i<s.size(); i++) {
            if(s[i]==s[i-1]) {
                count++;
            } else {
                t = t+to_string(count)+string(1, s[i-1]);
                count = 1;
            }
        }
        t = t+to_string(count)+string(1, s.back());
        return t;
    }
    string countAndSay(int n) {
        if(n<=0)
            return "";
        string s = "1";
        for(int i=1; i<n; i++) {
            cout<< s << endl;
            s = getNext(s);
        }
        return s;
    }
};
