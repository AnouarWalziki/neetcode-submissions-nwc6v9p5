class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int leftProd = 1;
        vector<int> leftPrefix(nums.size());
        for(int i = 0;  i < nums.size(); i++){
            leftPrefix[i] = leftProd;
            leftProd *= nums[i]; 
        }

        int rightProd = 1;
        vector<int> res(nums.size());
        for(int i = nums.size() - 1;  i >= 0; i--){
            res[i] = rightProd * leftPrefix[i];
            rightProd *= nums[i]; 
        }
        return res;
    }
};
