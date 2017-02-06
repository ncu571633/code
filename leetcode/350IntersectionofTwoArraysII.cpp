 Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:

    Each element in the result should appear as many times as it shows in both arrays.
    The result can be in any order.



class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> s(nums1.begin(), nums1.end());
        vector<int> v;
        for(int i=0; i<nums2.size(); i++) {
            if(s.count(nums2[i])) {
                auto it = s.find(nums2[i]);
                s.erase(it);
                v.push_back(nums2[i]);
            }
        }
        return v;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for(int i=0; i<nums1.size(); i++) {
            m[nums1[i]]++;
        }
        vector<int> v;
        for(int i=0; i<nums2.size(); i++) {
            if(m[nums2[i]]>0) {
                m[nums2[i]]--;
                v.push_back(nums2[i]);
            }
        }
        return v;
    }
};
