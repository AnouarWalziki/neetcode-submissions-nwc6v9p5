class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int prevEnd = intervals[0][1];
        int removed = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(prevEnd <= intervals[i][0])
                prevEnd = intervals[i][1];
            else{
                prevEnd = min(prevEnd, intervals[i][1]);
                removed++;
            }
        }
        return removed;
    }
};
