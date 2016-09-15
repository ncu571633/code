 Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> v(target+1, 0);
        v[0] = 1;
        for(int i=0; i<=target; i++){
            for(int j=0; j<nums.size(); j++) {
                if(nums[j] <= i)
                    v[i] += v[i-nums[j]];
            }
        }
        return v[target];
    }
};
