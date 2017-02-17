/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/

class Solution {
public:
    void restoreIpAddresses(string s, vector<string> &v, string &t, int start) {
        if(i==s.size()) {
            v.push_back(t);
            return ;
        }
        for(int i=start; i<s.size(); i++) {
            if(addressIsValid(s.substr(start, i-start+1)) {
                t.push_back(s.substr(start, i-start+1));
                restoreIpAddresses(s, v, t, i+1);
                t.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        string t;
        restoreIpAddresses(s, v, t, 0);
        return v;
    }
    bool addressIsValid(string s) {
        int n = atoi(s.c_str());
        if(0<=n && n<=255)
            return true;
        return false;
    }
};
