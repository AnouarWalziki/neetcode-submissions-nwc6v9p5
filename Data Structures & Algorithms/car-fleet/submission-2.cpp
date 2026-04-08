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

        stack<pair<int,int>> fleets;
        for(const auto& car : cars){
            if(!fleets.empty()){
                auto top = fleets.top();
                double topSp = (double)(target - top.first) / top.second;
                double currentSp = (double)(target - car.first) / car.second;
                if(currentSp <= topSp){
                    continue;
                }
            }

            fleets.push(car);
        }

        return fleets.size();
    }
};