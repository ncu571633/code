/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t t = 0;
        int b = 0;
        while(n) {
            t = (t<<1) + (n%2);
            n = n/2;
            b++;
        }
        return (t<<(32-b));
    }
};