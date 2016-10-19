Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2, -1);
        for(int i=0, j=nums.size()-1; i<=j; ) {
            int k = (i+j)/2;
            if(nums[k]==target) {
                i = k-1;
                while(nums[i]==target && i>=0)
                    i--;
                v[0] = (i+1);
                i = k+1;
                while(nums[i]==target && i<nums.size())
                    i++;
                v[1] = (i-1);
                return v;
            }
            
            if(nums[k]<target)
                i = k+1;
            if(nums[k]>target)
                j = k-1;
        }
        return v;
    }
};
