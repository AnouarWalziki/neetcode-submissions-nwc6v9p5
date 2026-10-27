class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& it1, const auto& it2){
            return it1[0] < it2[0];
        });

        vector<vector<int>> res;
        for(auto& interval : intervals){
            if(res.empty() || res.back()[1] < interval[0])
                res.push_back(interval);
            else
                res.back()[1] = max(res.back()[1], interval[1]);
        }
        return res;
    }
};
