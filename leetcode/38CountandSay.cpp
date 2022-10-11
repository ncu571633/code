The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence. 

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0)
            return "";
        string ret = "1";
        for(int i = 1; i < n; i++)
        {
            string temp;
            int count = 1;
            for(int j = 1; j <= ret.size(); j++)
            {
                if (j == ret.size())
                {
                    temp += to_string(count);
                    temp += ret[j-1];
                    break;
                }

                if (ret[j] == ret[j-1])
                {
                    count ++;
                }
                else
                {
                    temp += to_string(count);
                    temp += ret[j-1];
                    count = 1;
                }
            }
            ret = temp;
        }

        return ret;
    }
};
