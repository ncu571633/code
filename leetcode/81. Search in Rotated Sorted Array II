Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(!nums.size())
            return false;
        int i=0, j=nums.size()-1;
        while(i<=j) {
            int k = i+(j-i)/2;
            if(nums[k] == target)
                return true;
            if(nums[k]<nums[j]) {
                if(nums[k]<target && target<=nums[j])
                    i = k+1;
                else
                    j = k-1;
            } else if(nums[k] > nums[j]) {
                if(nums[i]<=target && target < nums[k])
                    j = k-1;
                else 
                    i = k+1;
            } else j--;
        }
        return false;
    }
};        
