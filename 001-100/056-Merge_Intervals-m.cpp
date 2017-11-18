// Given a collection of intervals, merge all overlapping intervals.
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
  public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2)
            return intervals;

        vector<Interval> ret;

        sort(intervals.begin(), intervals.end(),
             [](Interval &a, Interval &b) { return a.start < b.start; });
        ret.push_back(intervals.front());

        for (auto i = intervals.begin() + 1; i != intervals.end(); ++i) {
            if (i->start > ret.back().end)
                ret.push_back(*i);
            else if (i->end > ret.back().end)
                ret.back().end = i->end;
        }

        return ret;
    }
};