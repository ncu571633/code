rite a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".


class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
        || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        for(int i=0, j=s.length()-1; i<j; )
        {
            for(;!isVowel(s[i]) && i<j;)
                i++;
            for(;!isVowel(s[j]) && i<j;)
                j--;
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i++, j--;
        }
        return s;
    }
};