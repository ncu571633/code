/*
Write a function to find the longest common prefix string amongst an array of strings. 
*/

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        if(strs.empty())
            return s;
        for(int j=0; j<strs[0].size(); j++) {
            for(int i=1; i<strs.size(); i++) {
                if(strs[0][j]!=strs[i][j])
                    return s;
            }
            s=s+strs[0][j];
        }
        return s;
    }
};
