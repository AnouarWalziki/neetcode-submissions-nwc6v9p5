class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](pair<double, vector<int>>& a, pair<double, vector<int>>& b){
            return a.first < b.first;
        };
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, decltype(cmp)> maxHeap;

        // fill the heap 
        for(vector<int>& point : points){
            double distance = sqrt(pow(point[0], 2) + pow(point[1], 2)); 
            maxHeap.push(make_pair(distance, point));
            if(maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> res;
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
