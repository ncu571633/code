Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
You may return any answer array that satisfies this condition.

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Note:
1 <= A.length <= 5000
0 <= A[i] <= 5000

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ret, ret2;
        for(int i=0; i<A.size(); i++)
        {
            if(A[i] % 2 == 0)
                ret.push_back(A[i]);
            else
                ret2.push_back(A[i]);
        }
        ret.insert(ret.end(), ret2.begin(), ret2.end());
        return ret;
    }
};

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        for(int i = 0, j = A.size()-1; i<j; )
        {
            while(i<j && A[i]%2==0)
            {
                i++;
            }
            while(j>i && A[j]%2!=0)
            {
               j--; 
            }
            if (i!=j)
            {
                swap(A[i++], A[j--]);
            }
        }
        return A;
    }
};
