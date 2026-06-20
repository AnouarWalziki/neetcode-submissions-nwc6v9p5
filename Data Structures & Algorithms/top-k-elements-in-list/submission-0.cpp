class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int, int> count;
     for(int i : nums){
        count[i]++;
     }   

     vector<int> res;
    for(auto& [key, val] : count)
    {
        if(val >= k)
            res.push_back(key);
    }
    return res;
    }
};
