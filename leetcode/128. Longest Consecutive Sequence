 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int ret = 0;
        for(int i=0; i<nums.size(); i++) {
            int t = nums[i];
            if(m.count(t))
                continue;
            int left = m.count(t-1)? m[t-1]: 0;
            int right = m.count(t+1)? m[t+1]: 0;
            int sum = left+right+1;
            ret = max(sum, ret);
            m[t] = sum;
            m[t-left] = sum;
            m[t+right] = sum;
        }
        return ret;
    }
};
