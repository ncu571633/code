 Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity. 


v[i]: the length of longest increasing subsequence ends in nums[i]

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> v(nums.size(), 1);
        int r = 0;
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j])
                    v[i] = max(v[i], v[j]+1);
            }
            if(v[i]>r)
                r = v[i];
        }
        return r;
    }
};
