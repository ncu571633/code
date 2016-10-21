Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int add = 0;
        digits[0] ++;
        for(size_t i=0; i<digits.size(); i++) {
            digits[i] = digits[i] + add;
            if(digits[i] >=10) {
                digits[i] -= 10;
                add = 1;
            }
            else {
                add = 0;
                break;
            }
        }
        if(add)
            digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
