/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> events;
        for(auto& interval : intervals){
            events[interval.start]++;
            events[interval.end]--;
        }

        int active = 0;
        int res = 0;
        for(auto& event : events){
            active += event.second;
            res = max(res, active);
        }
        return res;
    }
};
