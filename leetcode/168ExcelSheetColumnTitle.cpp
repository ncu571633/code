Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        if(!n)
            return s;
        while(n) {
            if(n%26==0) {
                s = string(1, 'Z')+s;
                n = n/26;
                n--;
            } else {
                s = string(1, 'A'+n%26-1)+s;
                n = n/26;
            }
        }
        return s;
    }
};
