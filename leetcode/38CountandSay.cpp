The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence. 

class Solution {
public:
    string countAndSay(int n) {
        string a;
        if(!n)
            return a;
        a = string("1");
        for(int i=2; i<=n; i++) {
            string b;
            char c = a[0];
            int count = 1;
            for(int j=1; j<a.size(); j++) {
                if(a[j]!=c) {
                    b = b + to_string(count) + string(&c);
                    c = a[j], count=1;
                } else {
                    count++;
                }
            }
            b = b + to_string(count) + string(&c);
            swap(a, b);
        }
        return a;
    }
};
