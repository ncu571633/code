A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        for(int i=1; i<=nums.size()-2; i++)
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1])
                return i;
        if(nums[1] < nums[0])
            return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2])
            return nums.size()-1;
        return 0;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        while(low<high) {
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[mid+1])
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
