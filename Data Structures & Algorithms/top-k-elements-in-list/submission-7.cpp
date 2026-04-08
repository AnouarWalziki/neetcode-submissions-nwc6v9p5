class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> occur;
        for(int n : nums){
            occur[n]++;
        }
        std::vector<vector<int>> freq(nums.size() + 1);
        for(auto [key, val] : occur){
            freq[val].push_back(key);
        }
        vector<int> res;
        int i = freq.size() - 1;
        while(i >= 0 && res.size() < k){
            if(!freq[i].empty())
                res.insert(res.end(), freq[i].begin(), freq[i].end());
            i--;
        }
        return res;
    }
};
