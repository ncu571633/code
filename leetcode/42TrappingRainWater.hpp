 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2)
            return 0;
        vector<int> dp1(height.size(), 0); // max on the left
        for(int i=1; i<height.size(); i++) {
            dp1[i] = max(dp1[i-1], height[i-1]);
        }
        vector<int> dp2(height.size(), 0); // max on the right
        int ret = 0;
        for(int i=height.size()-2; i>=0; i--) {
            dp2[i] = max(dp2[i+1], height[i+1]);
            int t = min(dp2[i], dp1[i])-height[i];
            if(t>0)
                ret += t;
        }
        return ret;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2)
            return 0;

        vector<int> v(n, 0);
        for(int i=1; i<n; i++) {
            v[i] = max(v[i-1], height[i-1]);
        }
        int r = 0;
        int ret = 0;
        for(int i=n-2; i>=0; i--) {
            r = max(r, height[i+1]);
            int t = (min(v[i], r) - height[i]);
            ret += max(t, 0);            
        } 
        return ret;
    }
};
