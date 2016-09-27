 Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6]. 


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() < 2)
            return nums;
        vector<int> left(nums.size(), 1), right(nums.size(), 1);
        for(int i=1; i<nums.size(); i++)
            left[i] = left[i-1]*nums[i-1];
        for(int i=nums.size()-2; i>=0; i--)
            right[i] = right[i+1]*nums[i+1];
        for(int i=0; i<nums.size(); i++)
            left[i] *= right[i];
        return left;
    }
};
