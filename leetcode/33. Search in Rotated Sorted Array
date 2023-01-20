Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size())
            return -1;
        int i=0, j=nums.size()-1;
        while(i<=j) {
            int k = i+(j-i)/2;
            if(nums[k] == target)
                return k;
            if(nums[k]<nums[j]) {
                if(nums[k]<target && target<=nums[j])
                    i = k+1;
                else
                    j = k-1;
            } else { // nums[k] > nums[j]
                if(nums[i]<=target && target < nums[k])
                    j = k-1;
                else 
                    i = k+1;
            }
                
        }
        return -1;
    }
};
