class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1)
            return nums[0] == target ? 0 : -1;

        int l = 0;
        int r = nums.size() - 1;
        int cut = 0;

        if(nums[l] <= nums[r]){
            cut = l;
        }else{
            while(l <= r){
                int m = (l + r) / 2;
                int nxt = m + 1;

                if(nums[nxt] <= nums[m]){
                    cut = m;
                    break;
                }

                if(nums[m] <= nums[l]){
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
        }

        if(nums[0] <= target && target <= nums[cut]){
            l = 0;
            r = cut;
        } else if (nums[cut + 1] <= target && nums.size() - 1){
            l = cut + 1;
            r = nums.size() - 1;
        }
        else {
            return -1;
        }

        int res = -1;
        while(l <= r){
            int m = (l + r) / 2;
            if(nums[m] == target){
                res = m;
                break;
            }
            
            if(nums[m] < target){
               l = m + 1;
            }
            else{
                r = m - 1;
            }
        }

        return res;
    }
};
