class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = -1;
        for(int n : nums){
            if(last == n)
                break;

            last = n;
        }
        return last;
    }
};
