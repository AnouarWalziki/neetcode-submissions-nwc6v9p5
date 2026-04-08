class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> daysTemps;
        vector<int> res(temperatures.size());
        for(int i = 0; i < temperatures.size(); i++){
            while(!daysTemps.empty()){
                auto top = daysTemps.top();
                if(temperatures[i] > top.first){
                    res[top.second]= i - top.second;
                    daysTemps.pop();  
                } else {
                    break;
                }
            }
            daysTemps.push({temperatures[i], i});
        }
        return res;
    }
};
