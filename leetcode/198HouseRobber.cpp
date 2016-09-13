/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> v(nums.size(), 0);
        int r = 0;
        v[0] = nums[0];
        v[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++) {
            v[i] = nums[i];
            for(int j=0; j<i-1; i++) {
                v[i] = max(v[i], v[j]+nums[i]);
            }
            if(r < v[i])
                r = v[i];
        }
        return r;
    }
};

