Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False

Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.

class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        if (!n)
            return true;
        
        if(v[0]==0 && (1==v.size() || v[1]==0))
            v[0]=1, n--;
        for(int i=1; i<v.size(); i++)
        {
            if(v[i-1] == 0 && v[i]==0 
               && (i+1 >= v.size() || v[i+1]==0))
            {
                v[i]=1, n--;
            }
            if(n<=0)
                return true;
        }
        if(n<=0)
            return true;
        return false;
    }
};
