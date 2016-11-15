Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ret = 0;
        if(points.size()==1)
            return 1;
            
        for(int i=0; i<points.size(); i++) {
            map<double, int> m;
            m[INT_MAX] = 0;
            int dup = 1;
            for(int j=0; j<points.size(); j++) {
                if(i==j)
                    continue;
                if(points[i].x == points[j].x && points[i].y == points[j].y) {
                    dup++;
                    continue;
                }
                double k = INT_MAX;
                if(points[i].x != points[j].x)
                    k = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                m[k]++;
            }
            for(auto t: m) {
                ret = max(ret, t.second+dup);
            }
        }
        return ret;
    }
};
