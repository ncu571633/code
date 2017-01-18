Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5


class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        if(s.empty())
            return count;
        if(s[0]!=' ')
            count++;
        for(int i=1; i<s.size(); i++) {
            if(s[i-1]==' ' && s[i]!=' ')
                count++;
        }
        return count;
    }
};
