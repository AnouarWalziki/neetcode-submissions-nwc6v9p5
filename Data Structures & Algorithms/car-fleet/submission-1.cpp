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

        vector<double> times;
        for(auto&[pos, sp] : cars){
            times.push_back((double)(target - pos) / sp);
        } 

        double fleetTime = times[0];
        int fleetNb = 1;
        for(int i = 1; i < size; i++){
            if(times[i] > fleetTime){
                fleetNb += 1;
                fleetTime = times[i];
            }
        }

        return fleetNb;
    }
};