 All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> v;
        map<string, int> m;
        for(int i=0; i+9<s.size(); i++) {
            string t = string(s, i, 10);
            if(m.count(t))
                m[t] ++;
            else
                m[t] = 1;
        }
        for(map<string, int>::iterator it=m.begin(); it!=m.end(); it++) {
            if(it->second > 1)
                v.push_back(it->first);
        }
        return v;
    }
};
