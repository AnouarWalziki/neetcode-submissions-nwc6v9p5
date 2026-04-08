class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int,int>> cars;
        for(int i = 0; i < size; i++){
            cars.push_back({position[i], speed[i]});
        }
        
        // descending
        ranges::sort(cars, std::greater<>());

        vector<pair<int,int>> fleets;
        for(const auto& car : cars){
            if(!fleets.empty()){
                auto top = fleets.back();
                double topSp = (double)(target - top.first) / top.second;
                double currentSp = (double)(target - car.first) / car.second;
                if(currentSp <= topSp){
                    continue;
                }
            }

            fleets.push_back(car);
        }

        return fleets.size();
    }
};