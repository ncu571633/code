Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

class Solution {
public:
    static bool comp(Interval i, Interval j) {
        return i.start < j.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> v;
        sort(intervals.begin(), intervals.end(), comp);
        for(int i=0; i<intervals.size(); i++) {
            if(v.empty() || v.back().end<intervals[i].start) {
                v.push_back(intervals[i]);
            } else {
                v.back().start = min(v.back().start, intervals[i].start);
                v.back().end = max(v.back().end, intervals[i].end);
            }
        }
        return v;
    }
};


class Solution {
public:
    struct classcomp {
        static bool comp(const Interval& i, const Interval& j) {
        if(i.start < j.start)
            return true;
        if(i.start == j.start)
            return i.end < j.end;
        return false;
    }};
    vector<Interval> merge(vector<Interval>& intervals) {
        set<Interval, classcomp> s;
        for(int i=0; i<intervals.size(); i++) {
            Interval temp = intervals[i];
            if(s.empty()) {
                s.insert(temp);
                continue;
            }
            /*
            bool insert = false;
            for(set<Interval, classcomp>::iterator it=s.begin(); it!=s.end(); it++) {
                if(it->start <= temp.start && temp.start <= it->end) {
                    temp.start = min(it->start, temp.start);
                    temp.end = max(it->end, temp.end);
                    s.erase(it);
                    s.insert(temp);
                    insert = true;
                    break;
                }
                if(temp.end < it->start) {
                    break;
                }
            }
            if (!insert) {
                s.insert(temp);
            }
            */
        }
        return vector<Interval>(s.begin(), s.end());
    }
};
