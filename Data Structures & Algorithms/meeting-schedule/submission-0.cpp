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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty())
            return true;

        ranges::sort(intervals, [] (const auto& a, const auto& b){
            return a.start < b.start;
        });

        int prevEnd = intervals[0].end;
        int i = 1;
        bool res = true;
        while(i < intervals.size()){
            if(prevEnd <= intervals[i].start)
                prevEnd = intervals[i].end;
            else{
                res = false;
                break;
            }
            i++;
        }

        return res;
    }
};
