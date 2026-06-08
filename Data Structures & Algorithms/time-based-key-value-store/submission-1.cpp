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

        auto kVals = m_datas[key];
        int firstTimestamp = kVals.front().second;
        if(timestamp < firstTimestamp)
            return "";

        auto lastValAndTp = kVals.back();
        int lastTimestamp = lastValAndTp.second;
        if(timestamp >= lastTimestamp)
            return lastValAndTp.first;

        return findValueByTimestamp(kVals, timestamp);
    }

private:
    string findValueByTimestamp(const vector<pair<string, int>>& values, int timestamp){
        int l = 0, r = values.size() - 1;
        int m = 0;

        while(l <= r){
            m = (l + r) / 2;
            if(values[m].second == timestamp){
               return values[m].first;
            }

            if(values[m].second < timestamp){
                l = m + 1;
            } 
            else{
                r = m - 1;
            }
        }

        auto res = values[m].second;
        if(timestamp < res && m > 0){
            return values[m - 1].first;
        }

        return values[m].first;
    }

private:
    unordered_map<string, vector<pair<string, int>>> m_datas;
};
