/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0, b=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0) a++;
            if(nums[i]==1) b++;
        }
        for(int i=0; i<a; i++)
            nums[i] = 0;
        for(int i=a; i<a+b; i++)
            nums[i] = 1;
        for(int i=a+b; i<nums.size(); i++)
            nums[i] = 2;
    }
};