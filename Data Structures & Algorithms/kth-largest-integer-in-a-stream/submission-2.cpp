class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : kth(k), maxHeap(nums.begin(), nums.end()){
    }
    
    int add(int val) {
        maxHeap.push(val);
        auto heapCopy = maxHeap;
        int removed = 0;
        while(removed != kth - 1 && !heapCopy.empty()){
            heapCopy.pop();
            removed++;
        }
        return heapCopy.top();
    }

private:
    int kth;
    priority_queue<int> maxHeap;
};
