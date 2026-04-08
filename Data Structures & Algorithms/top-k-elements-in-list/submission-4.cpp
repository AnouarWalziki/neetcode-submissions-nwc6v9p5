class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     map<int, int> count;
     for(int i : nums){
        count[i]++;
     }   

    if(count.size() == 1){
        return {count.begin()->first};
    }
    
    vector<int> freq;
    for(auto& [key, val] : count){
        if(freq.empty()){
            freq.push_back(key);
            continue;
        }
        freq.push_back(key);
        int i = freq.size() - 2;
        int j = i + 1;
        while(i >= 0){
            if(count[freq[i]] < count[freq[j]]){
                swap(freq[i], freq[j]);
                i--;
                j--;
            } else{
                break;
            }
        }    
    }

    freq.resize(k);
    return freq;
    }
};
