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
        ranges::sort(intervals, [](const auto& l, const auto& r){
            return l.start < r.start;
        });

        return getMinRooms(intervals);
    }

    int getMinRooms(vector<Interval>& intervals){
        if(intervals.empty())
            return 0;
        
        vector<Interval> conflics;
        Interval prev = intervals[0];
        int i = 1;
        int n = intervals.size();
        while(i < n){
            if(prev.end <= intervals[i].start){
                prev = intervals[i];
            } 
            // overlap
            else if(prev.end > intervals[i].end){
                    conflics.push_back(prev);
                    prev = intervals[i];
            } else{
                    conflics.push_back(intervals[i]);
            }

            i++;
        }

        return 1 + getMinRooms(conflics);
    }
};
