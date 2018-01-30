/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            // value -> index map
            unordered_map<int, int> m;
            vector<int> ret;
            for(int i=0; i<nums.size(); i++) {
                if(m.count(target-nums[i])) {
                    ret.push_back(m[target-nums[i]]);
                    ret.push_back(i);
                    return ret;
                }
                m[nums[i]] = i;
            }
            return ret;
        }
};


/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        if(numbers.size() < 1)
            return v;
        
        set <int> s;
        for(int i=0; i<numbers.size(); i++)
        {
            if(s.count(numbers[i]) > 0)
            {//find one
                for(int j=0; j<i; j++)
                {
                    if(numbers[i]+numbers[j] == target)
                    {
                        v.push_back(j+1);
                        v.push_back(i+1);
                        return v;
                    }
                }
            }
            s.insert(target-numbers[i]);
        }
    }
};
