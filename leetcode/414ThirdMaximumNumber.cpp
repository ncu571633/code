/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:

Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.

Example 2:

Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:

Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

*/

#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int> nums) {
        set<int> s;
        for(int i=0; i<nums.size(); i++) {
            if(s.size()<3)
                s.insert(nums[i]);
            else{
                if(*(s.begin()) < nums[i])
                {
                    s.erase(s.begin());
                    s.insert(nums[i]);
                }
            }
        }
        if(s.size()<3)
            return *(s.rend());
        else
            return *(s.begin());
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long a=LONG_MIN, b=LONG_MIN, c=LONG_MIN;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>a) {
                c=b;
                b=a;
                a=nums[i];
            } else if(nums[i]>b && nums[i]<a) {
                    c=b;
                    b=nums[i];
            } else if(nums[i]>c && nums[i]<b) {
                c=nums[i];
            }
        }
        if(c==LONG_MIN)
            return a;
        return c;
            
    }
};

int main()
{
    int a[] = {1,2,2,5,3,5};
    Solution s;
    s.thirdMax(vector<int>(a, a+sizeof(a) / sizeof(int)));
}
