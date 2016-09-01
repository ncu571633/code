Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3


class NumArray {
private:
    vector<int> v;
public:
    NumArray(vector<int> &nums) {
        if(nums.size() == 0)
            return ;
        v.resize(nums.size()+1);
        v[0] = 0;
        for(int i=1; i<=nums.size(); i++)
            v[i] = v[i-1]+nums[i-1];
    }

    int sumRange(int i, int j) {
        return v[j+1] - v[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
