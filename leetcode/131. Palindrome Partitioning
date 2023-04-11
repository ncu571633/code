 Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> m;
        vector<string> v;
        partition(s, 0, m, v);
        return m;
    }
    void partition(string s, int i, vector<vector<string>>& m, vector<string> v) {
        if(i == s.size()) {
            m.push_back(v);
            return;
        }
        for(int j=i; j<s.size(); j++) {
            if(isPalindrome(s, i, j)) {
                v.push_back(string(s, i, j-i+1));
                partition(s, j+1, m, v);
                v.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int b, int e) {
        while(b<e)
            if(s[b++] != s[e--])
                return false;
        return true;
    }
};
