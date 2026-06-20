class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int,int>> cars;
        for(int i = 0; i < size; i++)
            cars.push_back({position[i], speed[i]});
        
        // descending
        ranges::sort(cars, std::greater<>());

        bool finish = false;
        while(!finish){
            for(auto&[pos, sp] : cars){
                pos += sp;
                if(pos >= target)
                    finish = true;
            }

            for(int i = 0; i < cars.size() - 1; i++){
                if((cars[i].first == cars[i+1].first) && (cars[i].second != cars[i+1].second)){
                    cars[i+1].second = cars[i].second;
                }
            }
        }

        int res = 0.;
        bool newFleet = false;
        for(int i = 0; i < cars.size() - 1; i++){
            if(cars[i].first == cars[i+1].first && !newFleet){
                newFleet = true;
                res+= 1;
            } 
            else if(cars[i].first != cars[i+1].first){
                newFleet = false;
                res+= 1;
            }
        }

        return res;
    }
};