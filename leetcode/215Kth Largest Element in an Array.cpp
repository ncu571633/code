/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 �� k �� array's length.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::multiset<int> s(nums.begin(), nums.end());
        k=nums.size()-k+1;
        for(std::set<int>::iterator it=s.begin(); it!=s.end(); it++, k--)
        {
            if(k==1)
                return *it;
        }
        return 0;
    }
};