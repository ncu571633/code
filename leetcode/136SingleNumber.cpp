/*
   given an array of integers, every element appears twice except for one. Find that single one.
 */

/*
XOR is commutative and associative (so the order in which it's done is irrelevant).
a number XORed with itself will always be zero.
zero XORed with a number will be that number
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = nums[0];
        for(int i=1; i<nums.size(); i++)
            temp ^= nums[i];
        return temp;
    }
};
