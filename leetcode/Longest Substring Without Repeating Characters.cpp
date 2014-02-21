class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0, j=0;
        bool c[256];
        memset(c, 0, 256);
        int len = 0;
        while(j<s.size())
        {
            if(c[ s[j] ] == true)
            {
                len = max(len, j-i);
                
                while( s[i] != s[j])
                    c[ s[i] ] = false, i++;
                i++, j++;
            }
            else
            {
                c[ s[j] ] = true;
                j++;
            }
        }
        len = max(len, j-i);
        return len;
    }
};
