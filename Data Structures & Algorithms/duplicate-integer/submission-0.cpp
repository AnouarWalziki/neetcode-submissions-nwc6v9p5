class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> uniqueNums; 
        for (int current : nums){
            uniqueNums.insert(current);
        }
        return uniqueNums.size() != nums.size();
    }
};