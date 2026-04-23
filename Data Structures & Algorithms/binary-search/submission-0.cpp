class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int m = (r + l) / 2;
            if(nums[m] == target){
                l = r = m;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        return target == nums[l] ? l : -1;
    }
};
