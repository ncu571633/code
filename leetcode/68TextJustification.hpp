Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int i = 0;
        while (i < words.size()) {
            int j = i, len = 0;
            while (j < words.size() && len + words[j].size() + j - i <= L) {
                len += words[j++].size();
            }
            string out;
            int space = L - len;
            for (int k = i; k < j; ++k) {
                out += words[k];
                if (space > 0) {
                    int tmp;
                    if (j == words.size()) { 
                        if (j - k == 1) tmp = space;
                        else tmp = 1;
                    } else {
                        if (j - k - 1 > 0) {
                            if (space % (j - k - 1) == 0) tmp = space / (j - k - 1);
                            else tmp = space / (j - k - 1) + 1;
                        } else tmp = space;
                    }
                    out.append(tmp, ' ');
                    space -= tmp;
                }
            }
            res.push_back(out);
            i = j;
        }
        return res;
    }
};
