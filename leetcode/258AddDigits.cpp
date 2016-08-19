/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
*/

class Solution {
public:
    int addDigits(int num) {
        if(num<10)
            return num;
        
        int temp = 0;
        while(num)
        {
            temp += num%10;
            num /= 10;
        }
        return addDigits(temp);
    }
};


/*
numbers who are divisible by 9 have a property that adding up their digits in such a way would eventually lead to a 9.
*/

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        if(num%9)
            return num%9;
        return 9;
        
    }
};
