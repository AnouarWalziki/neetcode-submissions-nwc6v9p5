class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
     for(int i : nums){
        count[i]++;
     }
     vector<vector<int>> freq(nums.size() + 1);
     for(auto& [key, val] : count){
        freq[val].push_back(key);
     }

     vector<int> res;
     for(auto it = freq.rbegin(); it < freq.rend(); it++)
     {
        for(int i : *it){
            if(res.size() >= k)
                break;
            res.push_back(i);
        }
     }
    return res;
    }
};
