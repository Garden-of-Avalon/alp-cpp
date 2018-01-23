// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
// required.

// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return 2.

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
    int minMeetingRooms(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto &i, auto &j) { return i.start < j.start; });

        priority_queue<int, vector<int>, greater<int>> endtime;

        for (auto &i : intervals) {
            if (!endtime.empty() && i.start >= endtime.top())
                endtime.pop();
            endtime.push(i.end);
        }

        return endtime.size();
    }
};