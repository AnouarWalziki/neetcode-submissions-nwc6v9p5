class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> mp; 
        for (int current : nums){
            if(mp.count(current) != 0)
                return true;
            mp[current] = current;
        }
        return false;
    }
};