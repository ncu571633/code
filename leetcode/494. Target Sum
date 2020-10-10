 You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:

    The length of the given array is positive and will not exceed 20.
    The sum of elements in the given array will not exceed 1000.
    Your output answer is guaranteed to be fitted in a 32-bit integer.


class Solution {
public:
    void findTargetSumWays(vector<int> nums, int S, int start, int& count) {
        if(start == nums.size())
        {
            if(!S)
                count++;
            return ;
        }
        findTargetSumWays(nums, S+nums[start], start+1, count);
        findTargetSumWays(nums, S-nums[start], start+1, count);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        findTargetSumWays(nums, S, 0, count);
        return count;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int> nums, int S, int start, vector<map<int, int>>& v) {
        if(start == nums.size())
            return S==0;
        if(v[start].count(S))
            return v[start][S];
        int a = findTargetSumWays(nums, S+nums[start], start+1, v);
        int b = findTargetSumWays(nums, S-nums[start], start+1, v);
        v[start][S] = a+b;
        return v[start][S];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<map<int, int>> v(nums.size());
        return findTargetSumWays(nums, S, 0, v);
    }
};
