 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:

[
  [7],
  [2, 2, 3]
]


class Solution {
public:
    void combinationSum(vector<int>& candidates, int target, int start, vector<vector<int>>& m, vector<int>&v) {
        if(target==0) {
            m.push_back(v);
            return;
        }
        for(int i=start; i<candidates.size(); i++) {
            if(target-candidates[i]<0) continue;
            if(i>start && candidates[i]==candidates[i-1]) continue;
            v.push_back(candidates[i]);
            combinationSum(candidates, target-candidates[i], i, m, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> m;
        vector<int>v;
        if(candidates.empty())  return m;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, 0, m, v);
        return m;
    }
};
