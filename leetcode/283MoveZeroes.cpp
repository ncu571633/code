/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i])
            {
                nums[index++] = nums[i];
            }
        }
        for(;index<nums.size();index++)
        {
            nums[index] = 0;
        }
    }
};


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                if(i!=j)
                    swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
