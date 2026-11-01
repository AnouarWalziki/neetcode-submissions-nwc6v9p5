class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> noneOverlaps;
        int removed = 0;
        for(auto interval : intervals){
            if(noneOverlaps.empty() || noneOverlaps.back()[1] <= interval[0])
                noneOverlaps.push_back(interval);
            else
                removed++;
        }
        return removed;
    }
};
