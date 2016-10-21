/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.

1 + 99 = 100, 99 + 100 = 199

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
*/

#include <string>
#include <algorithm>
using namespace std;
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
            s = s + std::to_string(t);
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
    
    bool DFS(string num1, string num2, string num3) {
        if(num3.empty())
            return true;
        string sum = addStrings(num1, num2);
        int i = 0;
        for(; i<sum.size(); i++) {
            if(sum[i] != num3[i]) {
                break;    
            }
        }
        if(i==sum.size()) {
            return DFS(num2, sum, num3.substr(sum.size()));
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        if(num.size()<3)
            return false;
        
        for(int i=1; i<=num.size()-2; i++) {
            string num1 = num.substr(0, i);
            for(int j=i+1; j<=num.size()-1; j++) {
                if(num2[j]=='0')
                    continue;
                string num2 = num.substr(i, j-i);
                string num3 = num.substr(j);
                if(DFS(num1, num2, num3))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    s.isAdditiveNumber("19910011992");
    return 1;
}
