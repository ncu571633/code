 Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number. 

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(1, 1);
        int i2=0, i3=0, i5=0;
        
        for(int i=1; i<n; i++)
        {
            int t = min(v[i2]*2, min(v[i3]*3, v[i5]*5));
            v.push_back(t);
            if(t == v[i2]*2) i2++;
            if(t == v[i3]*3) i3++;
            if(t == v[i5]*5) i5++;
        }
        return v.back();
    }
};
