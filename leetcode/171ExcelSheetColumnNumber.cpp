/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/


class Solution {
public:
    int titleToNumber(string s) {
        int no = 0;
        for(int i=s.length()-1; i>=0; i--)
        {
            no += (s[i]-'A'+1)*pow(26, (s.length()-i-1));
        }
        return no;
    }
};