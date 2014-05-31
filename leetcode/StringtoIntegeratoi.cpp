/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. 
*/

class Solution {
public:
    int atoi(const char *str) {

        int number = 0, count = 0;
        for(int i=strlen(str)-1; i>=0; i--)
        {
            if('0'<=str[i] && str[i]<='9')
            {
                number+=(str[i]-'0')*pow(10, count);
                count++;
            }
        }
        if(str[0]=='-')
            return -number;
        else
            return number;
    }
};
