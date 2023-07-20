 Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(size_t i=0; i<nums.size(); i++) {
            m[nums[i]] ++;
        }
        priority_queue<pair<int, int>> p;
        for(auto it=m.begin(); it!=m.end(); it++) {
            p.push(make_pair(it->second, it->first));
        }
        vector<int> v;
        v.reserve(k);
        for(int i=0; i<k; i++) {
            v.push_back(p.top().second);
            p.pop();
        }
        return v;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        multimap<int, int> m2;
        for(auto it=m.begin(); it!=m.end(); it++) {
            m2.insert({it->second, it->first});
        }
        int i=0;
        vector<int> v;
        for(auto it=m2.rbegin(); it!=m2.rend()&&i<k; i++, it++) {
            v.push_back(it->second);
        }
        return v;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        multimap<int, int, greater<int>> m2;
        for(auto it=m.begin(); it!=m.end(); it++) {
            m2.insert({it->second, it->first});
        }
        int i=0;
        vector<int> v;
        for(auto it=m2.begin(); it!=m2.end()&&i<k; i++, it++) {
            v.push_back(it->second);
        }
        return v;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(auto a: m)
        {
            bucket[a.second].push_back(a.first);
        }
        
        vector<int> v;
        for(int i=nums.size(); i>=0; i--) {
            for(auto a: bucket[i])
            {
                v.push_back(a);
                if(v.size() == k)
                    return v;
            }
        }
        return v;
    }
};
