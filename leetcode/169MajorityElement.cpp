/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> temp;
        for(int i=0; i<nums.size(); i++)
        {
            if(!temp.count(nums[i]))
                temp[nums[i]] = 1;
            else
                temp[nums[i]] ++;
            if(temp[nums[i]]> nums.size()/2)
                return nums[i];
        }
        return 0;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int number = 0, count = 0; 
        for(int i=0; i<nums.size(); i++)
        {
            if(!count)
                number = nums[i];
            if(number == nums[i])
                count++;
            else
                count --;
        }
        return number;
    }
};
