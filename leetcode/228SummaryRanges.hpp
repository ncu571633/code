 Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        if(!nums.size())
            return v;
        int begin=nums[0], last=nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]!=last+1) {
                if(begin==last)
                    v.push_back(to_string(begin));
                else
                    v.push_back(to_string(begin)+"->"+to_string(last));
                begin = nums[i];
            }
            last = nums[i];
        }
        if(begin==last)
            v.push_back(to_string(begin));
        else
            v.push_back(to_string(begin)+"->"+to_string(last));      
        return v;
    }
};
