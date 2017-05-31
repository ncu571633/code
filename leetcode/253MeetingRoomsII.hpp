Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for(auto a: intervals) {
            m[a.start]++;
            m[a.end]--;
        }
        
        int ret = 0, rooms = 0;
        for(auto a: m) {
            rooms += a.second;
            ret = max(ret, rooms);
        }

        return ret;
    }
}
