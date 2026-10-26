class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = 0;
        int r = intervals.size() - 1;
        int target = newInterval[0];
        while (l <= r){
            int m = (l + r) / 2;
            if(intervals[m][0] < target)
                l = l + 1;
            else
                r = r - 1;
        }

        intervals.insert(intervals.begin() + l, newInterval);

        vector<vector<int>> res;
        for(auto& interval : intervals){
            if(res.empty() || res.back()[1] < interval[0])
                res.push_back(interval);
            else
                res.back()[1] = max(interval[1], res.back()[1]);
        }

        return res;
    }
};
