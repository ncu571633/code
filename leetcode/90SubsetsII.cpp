 Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]


class Solution {
public:
    void subsetsWithDup(vector<int>& nums, int start, vector<vector<int>>& m, vector<int> v) {
        for(int i=start; i<nums.size(); i++) {
            if(i>start && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            m.push_back(v);
            subsetsWithDup(nums, i+1, m, v);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> m;
        vector<int>v;
        m.push_back(v);
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, 0, m, v);
        return m;
    }
};
