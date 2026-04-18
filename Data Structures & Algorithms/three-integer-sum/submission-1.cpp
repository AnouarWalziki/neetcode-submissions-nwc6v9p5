class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> unique;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            int target = -(nums[i]);
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == target){
                    vector<int> triplet{nums[i], nums[l], nums[r]};
                    unique.insert(unique.end(), triplet);
                    l++;
                    r--;
                } else if (sum < target){
                    l++;
                } else {
                    r--;
                }
            }
        }

        vector<vector<int>> res;
        for (const auto& triplet : unique){
            res.insert(res.end(), triplet);
        }
        return res;
    }
};
