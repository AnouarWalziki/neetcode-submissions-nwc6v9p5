class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int& nbr : nums){
            minHeap.push(nbr);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};
