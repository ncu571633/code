Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ret;
        for(int k=0; k<nums.size(); k++) {
            if(nums[k] > 0)
                break;
            int target = -nums[k];
            int i=k+1, j=nums.size()-1;
            while(i<j) {
                if(nums[i]+nums[j] == target) {
                    vector<int> v;
                    v.push_back(nums[k]);
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    ret.insert(v);
                    i++, j--;
                } else if (nums[i]+nums[j] < target) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        return vector<vector<int>> (ret.begin(), ret.end());
    }
};
