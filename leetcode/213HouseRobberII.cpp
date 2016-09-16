After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police

class Solution {
public:
    int rob(vector<int>& nums, int s, int e) {
        vector<int> v(e, 0);
        v[s] = nums[s];
        v[s+1] = max(nums[s], nums[s+1]);
        for(int i=s+2; i<e; i++) {
            v[i] = max(v[i-2]+nums[i], v[i-1]);
        }
        return v.back();        
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        return max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));
    }
};
