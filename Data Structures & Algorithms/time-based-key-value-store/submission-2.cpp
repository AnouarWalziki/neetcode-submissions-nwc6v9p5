class TimeMap {
public:
    TimeMap() {
        
    }

    void set(string key, string value, int timestamp) {
        m_datas[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if(!m_datas.contains(key))
            return "";

        auto& values = m_datas[key];
        int l = 0, r = values.size() - 1;
        string res;

        while(l <= r){
            int m = (l + r) / 2;
            if(values[m].second == timestamp){
                res = values[m].first;
                break;
            }

            if(values[m].second < timestamp){
                res = values[m].first;
                l = m + 1;
            } 
            else{
                r = m - 1;
            }
        }
        return res;
    }

private:
    unordered_map<string, vector<pair<string, int>>> m_datas;
};
