Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3

Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.


/*
i = 1: 1~9   count: 9
i = 2: 10~99 count:90
i = 3: 100~999 count:900
*/

class Solution {
public:
    int findNthDigit(int n) {
        int i=1;
        long long first = 1;
        while(n>9*first*i)
        {
            n = n - 9*i*first;
            first = 10*first;
            i++;
        }
        first = first+(n-1)/i;
        return to_string(first)[(n-1)%i]-'0';
    }
};
