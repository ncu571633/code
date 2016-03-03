/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::map<int, bool> temp;
        for(int i=0; i<nums.size(); i++)
        {
            if(temp.count(nums[i]))
                return true;
            temp[nums[i]] = 0;
        }
        return false;
    }
};
