class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[l] + nums[r] + nums[i];
                if (sum < 0){
                    l++;
                } else if(sum > 0){
                    r--;
                } else{
                    res.insert(res.end(), {nums[i], nums[l], nums[r]});
                    l++;
                    while(nums[l] == nums[l - 1] && l < r){
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
