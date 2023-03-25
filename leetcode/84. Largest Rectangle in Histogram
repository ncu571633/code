Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ret = 0;
        for(int i=0; i<h.size(); i++)
        {
            if (i + 1 < h.size() && h[i] <= h[i + 1]) {
                continue;
            }
            int minH = h[i];
            for(int j=i; j>=0; j--)
            {
                minH = min(h[j], minH);
                ret = max(ret, minH*(i-j+1));
            }
        }
        return ret;
    }
};


