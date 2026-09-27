class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[slow];
        int maxId = 0;
        
        // detect cycle
        while(slow != fast){
            maxId = max(fast, maxId);
            slow = nums[slow];
            maxId = max(nums[fast], maxId);
            fast = nums[nums[fast]];
        }

        return nums[maxId];
    }
};
