Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.



class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0, j = nums.size()-1;
        while(i<=j)
        {
            int k = (i+j)/2;
            if(nums[i]<=nums[k] && nums[k]<=nums[j])
                return nums[i];
            else if(nums[j]<=nums[i] && nums[i]<=nums[k])
                i = k+1;
            else if(nums[k]<=nums[j] && nums[j]<=nums[i])
                j = k;
        }
        return nums[i];
    }
};
