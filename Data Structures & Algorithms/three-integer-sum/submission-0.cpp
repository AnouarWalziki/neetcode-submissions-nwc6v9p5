class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        set<vector<int>> unique;
        for(int i = 0; i < size - 2; i++){
            int j = i + 1;
            int k = j + 1;
            while(j < size - 1){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    vector<int> triplet{nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    unique.insert(unique.end(), triplet);
                }

                if(k == size - 1){
                    j++;
                    k = j + 1;
                } else if (k < size - 1){
                    k++;
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
