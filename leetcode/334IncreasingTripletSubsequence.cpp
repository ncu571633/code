/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ¡Ü i < j < k ¡Ü n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> smaller(nums.size(), 0), greater(nums.size(), 0);
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
                if(nums[j]<nums[i]) {
                    smaller[i] = true;
                    break;
                }
            }
            for(int j=nums.size()-1; j>i; j--) {
                if(nums[j]>nums[i]) {
                    greater[i] = true;
                    break;
                }               
            }
        }
            for(int i=0; i<nums.size(); i++)
                if(smaller[i] && greater[i])
                    return true;
            return false;
    }
};