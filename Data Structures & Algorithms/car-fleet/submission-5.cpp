class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int,int>> cars;
        for(int i = 0; i < size; i++){
            cars.push_back({position[i], speed[i]});
        }
        
        // descending
        ranges::sort(cars.rbegin(), cars.rend()); // nice trick

        vector<double> timings;
        for(const auto& car : cars){
            double currentSp = (double)(target - car.first) / car.second;
            if(!timings.empty()){
                auto topSp = timings.back();
                if(currentSp <= topSp){
                    continue;
                }
            }

            timings.push_back(currentSp);
        }

        return timings.size();
    }
};