class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        while(maxHeap.size() > 1){
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();

            int curr = first - second;
            if(curr != 0)
                maxHeap.push(curr); 
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
