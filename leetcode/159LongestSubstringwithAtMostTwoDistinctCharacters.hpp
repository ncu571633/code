 

Given a string S, find the length of the longest substring T that contains at most two distinct characters.
For example,
Given S = “eceba”,
T is “ece” which its length is 3. 


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> m;
        int ret = 0, left = 0;
        for(int i=0; i<s.size(); i++) {
            m[s[i]]++;
            while(m.size()>2) {
                m[s[left]]--;
                if(m[s[left]] == 0)
                    m.erase(s[left]);
                left++;
            }
            ret = max(ret, i-left+1);
        }
        return ret;
    }
}
