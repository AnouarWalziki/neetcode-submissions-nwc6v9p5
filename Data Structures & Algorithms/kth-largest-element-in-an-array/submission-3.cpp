class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = nums[0];
        quickSelect(nums, 0, nums.size() - 1, k, res);
        return res;
    }

private:
    int partition(vector<int>& nums, int low, int high){
        //choose pivot
        int pivot = nums[high];

        // index of the last smaller element that pivot
        int i = low - 1;

        //moves all elements smaller than pivot to the left
        for(int j = low; j < high; j++){
            if(nums[j] < pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }

        // move pivot at the right index
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    void quickSelect(vector<int>& nums, int low, int high, int k, int& res){
        if(low >= high)
            return;

        int pivot = partition(nums, low, high);
        if(pivot == nums.size() - k){
            res = nums[pivot];
            return;
        }

        quickSelect(nums, low, pivot - 1, k , res);
        quickSelect(nums, pivot + 1, high, k , res);
    }
};
