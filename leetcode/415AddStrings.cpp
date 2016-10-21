Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.


class Solution {
public:
    string addStrings(string num1, string num2) {
        string s;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        int i = 0;
        for(; i<num1.size()&&i<num2.size(); i++) {
            int t = num1[i]-'0'+num2[i]-'0'+carry;
            carry = t/10;
            t = t%10;
            s = s + to_string(t);
        }
        for(; i<num1.size(); i++) {
            int t = num1[i]-'0'+carry;
            carry = t/10;
            t = t%10;
            s = s + to_string(t);            
        }
        for(; i<num2.size(); i++) {
            int t = num2[i]-'0'+carry;
            carry = t/10;
            t = t%10;
            s = s + to_string(t);            
        }        
        if(carry)
            s = s + to_string(carry);
        reverse(s.begin(), s.end());
        return s;
    }
};
