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
        vector<pair<int, int>> events;
        for(auto& interval : intervals){
            events.push_back({interval.start, 1});
            events.push_back({interval.end, -1});
        }

        ranges::sort(events, [](const auto& l, const auto& r){
            return l.first == r.first ? l.second < r.second : l.first < r.first;
        });

        int active = 0;
        int res = 0;
        for(auto& event : events){
            active += event.second;
            res = max(res, active);
        }
        return res;
    }
};
