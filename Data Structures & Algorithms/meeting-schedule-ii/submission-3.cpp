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
        ranges::sort(intervals, [](const auto& a, const auto& b){
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto& interval : intervals){
            if(!minHeap.empty() && minHeap.top() <= interval.start)
                minHeap.pop();
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};
