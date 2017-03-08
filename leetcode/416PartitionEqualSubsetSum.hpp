Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

    Each of the array element will not exceed 100.
    The array size will not exceed 200.

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.


class Solution {
public:
    bool canPartition(vector<int>& nums, int sum, int start) {
        if(start >= nums.size()) {
            return (!sum);
        }
        if(canPartition(nums, sum+nums[start], start+1))
            return true;
        return canPartition(nums, sum-nums[start], start+1);
    }
    bool canPartition(vector<int>& nums) {
        return canPartition(nums, 0, 0);
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums, int sum, int start, vector<unordered_map<int, int>>& v) {
        if(start >= nums.size()) {
            return (!sum);
        }
        if(v[start].count(sum))
            return v[start][sum];
        if(canPartition(nums, sum+nums[start], start+1, v)) {
            v[start][sum] = true;
            return true;
        }
        v[start][sum] = canPartition(nums, sum-nums[start], start+1, v);
        return v[start][sum];
    }
    bool canPartition(vector<int>& nums) {
        vector<unordered_map<int, int>> v;
        v.resize(nums.size());
        return canPartition(nums, 0, 0, v);
    }
};


