class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        while(maxHeap.size() > 1){
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();

            if(first == second)
                continue;

            maxHeap.push(max(second, first) - min(second, first));
        }

        if(maxHeap.empty())
            return 0;
        return maxHeap.top();
    }
};
