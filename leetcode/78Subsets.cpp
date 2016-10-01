 Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


class Solution {
public:
    void subsets(vector<int>& nums, int start, vector<vector<int>>&m, vector<int>&v) {
        for(int i=start; i<nums.size(); i++) {
            v.push_back(nums[i]);
            m.push_back(v);
            subsets(nums, i+1, m, v);
            v.pop_back();
        }        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> m;
        vector<int>v;
        m.push_back(v);
        subsets(nums, 0, m, v);
        return m;
    }
};
