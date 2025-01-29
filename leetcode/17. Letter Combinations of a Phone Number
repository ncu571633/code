Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


class Solution {
public:
    void letterCombinations(string digits, vector<string>& ret, string s, string dict[], int start) {
        if(start == digits.size()) {
            ret.push_back(s);
            return ;
        }
            int index = digits[start]-'0';
            for(int j=0; j<dict[index].size(); j++) {
                s += string(1, dict[index][j]);
                letterCombinations(digits, ret, s, dict, start+1);
                s.pop_back();
            }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty())
            return ret;
        string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinations(digits, ret, "", dict, 0);
        return ret;
    }
};
