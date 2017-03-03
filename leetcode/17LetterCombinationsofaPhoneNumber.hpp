Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


class Solution {
private:
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(digits.empty())
            return v;
        string s;
        string dict[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinations(digits, v, s, 0, dict);
        return v;
    }
    void letterCombinations(string digits, vector<string>& v, string& s, int start, string dict[]) {
        if(start == digits.size() && s.size()==digits.size())  {
            v.push_back(s);
            return ;
        }
        for(int i=start; i<digits.size(); i++) {
            int k=digits[i]-'0';
            for(int j=0; j<dict[k].size(); j++) {
                s = s+string(1, dict[k][j]);
                letterCombinations(digits, v, s, i+1, dict);
                s.pop_back();
            }
        }
    }
};
