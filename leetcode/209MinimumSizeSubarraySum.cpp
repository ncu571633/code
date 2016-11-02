 Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint. 


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum=0;
        int minL =INT_MAX;
        for(int start=0, end=0; start<nums.size()&&end<nums.size(); ) {
            while(sum<s && end<nums.size()) {
                sum += nums[end];
                end++;
            }
            while(sum>=s && start<end) {
                minL = min(minL, end-start);
                sum -= nums[start];
                start++;
            }
        }
        return (minL==INT_MAX)? 0: minL;
    }
};
