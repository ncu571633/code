 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:

[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]


class Solution {
public:
    void permuteUnique(vector<int>& nums, set<vector<int>>& s, vector<int>& v, vector<bool>& visited) {
        if(v.size() == nums.size()) {
            s.insert(v);
            return ;
        }
        for(int i=0; i<nums.size(); i++) {
            if(visited[i])
                continue;
            visited[i] = true;
            v.push_back(nums[i]);
            permuteUnique(nums, s, v, visited);
            visited[i] = false;
            v.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> v;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        permuteUnique(nums, s, v, visited);
        vector<vector<int>> m(s.begin(), s.end());
        return m;
    }
};


class Solution {
public:
    void permuteUnique(vector<int>& nums, vector<vector<int>>& s, vector<int>& v, vector<bool>& visited) {
        if(v.size() == nums.size()) {
            s.push_back(v);
            return ;
        }
        for(int i=0; i<nums.size(); i++) {
            if(visited[i])
                continue;
            if(i>0 && nums[i]==nums[i-1] && visited[i-1]==0)
                continue;
            visited[i] = true;
            v.push_back(nums[i]);
            permuteUnique(nums, s, v, visited);
            visited[i] = false;
            v.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> v;
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        permuteUnique(nums, ret, v, visited);
        return ret;
    }
};
