/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

class Solution {
public:
    bool share(string s1, string s2)
    {
        //if(s1.empty() || s2.empty())
        for(int i=0; i<s1.length(); i++)
            //if(s2.find(s1[1])!=std::string::npos)
            for(int j=0; j<s2.length(); j++)
                if(s1[i] == s2[j])
                    return true;
        return false;
    }
    int maxProduct(vector<string>& words) {
        int max = 0;
        for(int i=0; i<words.size(); i++)
        {
            for(int j=i+1; j<words.size(); j++)
            {
                int p = words[i].length()*words[j].length();
                if(p>max)
                {
                    if(!share(words[i], words[j]))
                    {
                        max = p;
                    }
                }
            }
        }
        return max;
    }
};