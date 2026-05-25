class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = 0;
        while(l <= r){
            int m = (l + r) / 2;
            if(m == 0){
                res = min(nums[m], nums[r]);
                break; 
            }

            if(nums[m] < nums[m - 1]){
                res = nums[m];
                break;
            }

            if(nums[m] < nums[r]){
                r = m - 1;
            } 
            else {
                l = m + 1;
            }
        }
        return res;
    }
};
