 You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:

Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

Note:

    The number of given pairs will be in the range [1, 1000].

class Solution {
public:
    static bool sortPairs(vector<int> v1, vector<int> v2)
    {
        return v1[0] < v2[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(!n)
            return 0;
        sort(pairs.begin(), pairs.end(), sortPairs);
        vector<int> dp(n, 1);
        for(int i = 1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(pairs[i][0] > pairs[j][1])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    static bool sortPairs(vector<int> v1, vector<int> v2)
    {
        return v1[1] < v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(!n)
            return 0;
        sort(pairs.begin(), pairs.end(), sortPairs);
        int ret=0, end=INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(pairs[i][0] > end)
            {
                ret++;
                end = pairs[i][1];
            }
        }
        return ret;
    }
};
